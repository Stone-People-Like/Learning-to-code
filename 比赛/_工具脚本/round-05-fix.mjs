// 修复：重新提取含表格的题目，把表格转成 Markdown
const fs = await import("node:fs/promises");
const task = await claimTaskSpace(2);
const page = task.page("p1");

const setId = "2109427710507986944";
const pid = "2109427710528958474";

await page.goto(`https://pintia.cn/problem-sets/${setId}/exam/problems/type/7?problemSetProblemId=${pid}`);
await page.waitForTimeout(2500);

const data = await page.evaluate(() => {
  const left = document.querySelector("div.left_TFoYO") || document.querySelector("main");
  const md = left.querySelector("div.rendered-markdown");
  md.querySelectorAll('span[style*="-9999px"], [aria-hidden="true"].katex-html').forEach((n) => n.remove());
  md.querySelectorAll(".katex").forEach((k) => {
    const tex = k.querySelector('annotation[encoding="application/x-tex"]');
    if (tex) { const s = document.createElement("span"); s.textContent = tex.textContent; k.replaceWith(s); }
  });

  // 表格转 Markdown
  const toMd = (table) => {
    const rows = [...table.querySelectorAll("tr")].map((tr) =>
      [...tr.querySelectorAll("th,td")].map((c) => c.innerText.replace(/\s+/g, " ").trim())
    );
    if (!rows.length) return "";
    const cols = Math.max(...rows.map((r) => r.length));
    const pad = (r) => { const c = [...r]; while (c.length < cols) c.push(""); return c; };
    const head = pad(rows[0]);
    const sep = head.map(() => "---");
    const body = rows.slice(1).map(pad);
    return [head, sep, ...body].map((r) => "| " + r.join(" | ") + " |").join("\n");
  };

  const blocks = [];
  const push = (lang, text) => { if (text != null && text !== "") blocks.push({ lang, text }); };
  const walk = (el) => {
    for (const child of el.children) {
      const tag = child.tagName.toLowerCase();
      if (child.hasAttribute && child.hasAttribute("data-code")) {
        const lines = [...child.querySelectorAll(".cm-content .cm-line")].map((l) => l.innerText);
        push(child.getAttribute("data-lang"), lines.join("\n"));
        continue;
      }
      if (/^h[2-4]$/.test(tag)) { push("heading", child.innerText.trim()); continue; }
      if (tag === "p") { push("p", child.innerText.trim()); continue; }
      if (tag === "pre") { push("pre", child.innerText); continue; }
      if (tag === "ul" || tag === "ol") { push("list", child.innerText.trim()); continue; }
      if (tag === "table") { push("table", toMd(child)); continue; }
      if (tag === "img") { push("img", child.getAttribute("src")); continue; }
      if (tag === "blockquote") { push("p", child.innerText.trim()); continue; }
      walk(child);
    }
  };
  walk(md);
  const firstText = md.firstChild && md.firstChild.nodeType === 3 ? md.firstChild.textContent.trim() : "";
  if (firstText) blocks.unshift({ lang: "p", text: firstText });

  const txt = left.innerText || "";
  return {
    score: (txt.match(/分数\s*(\d+)/) || [])[1] || null,
    author: (txt.match(/作者\s*([^\n]+)/) || [])[1]?.trim() || null,
    unit: (txt.match(/单位\s*([^\n]+)/) || [])[1]?.trim() || null,
    restrict: (txt.match(/代码长度限制[\s\S]*?栈限制\s*\d+\s*KB/) || [null])[0],
    blocks,
  };
});

console.log(JSON.stringify(data.blocks.filter((b) => b.lang === "table"), null, 2));

// 写回 JSON
const p = `/tmp/pta-sets/${setId}.json`;
const d = JSON.parse(await fs.readFile(p, "utf8"));
const idx = d.results.findIndex((r) => r.id === pid);
d.results[idx] = { id: pid, ...data };
await fs.writeFile(p, JSON.stringify(d, null, 2));
console.log("updated");