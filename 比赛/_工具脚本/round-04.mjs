// 第四轮：按索引抓取题目正文。每次处理 from..to 区间，结果写入 /tmp/pta-sets/<id>.json
const fs = await import("node:fs/promises");
const task = await claimTaskSpace(2);
const page = task.page("p1");

await fs.mkdir("/tmp/pta-sets", { recursive: true });
const index = JSON.parse(await fs.readFile("/tmp/pta-index.json", "utf8"));

const FROM = 0, TO = index.length; // 可调区间

for (let si = FROM; si < TO; si++) {
  const set = index[si];
  const outPath = `/tmp/pta-sets/${set.id}.json`;
  let done = [];
  try { done = JSON.parse(await fs.readFile(outPath, "utf8")).results || []; } catch {}
  const doneIds = new Set(done.map((d) => d.id));

  for (let i = 0; i < set.order.length; i++) {
    const pid = set.order[i];
    if (doneIds.has(pid)) continue;
    const type = set.types[0].type;
    await page.goto(`https://pintia.cn/problem-sets/${set.id}/exam/problems/type/${type}?problemSetProblemId=${pid}`);
    await page.waitForTimeout(1800);

    const data = await page.evaluate(() => {
      const left = document.querySelector("div.left_TFoYO") || document.querySelector("main");
      const md = left?.querySelector("div.rendered-markdown");
      if (!md) return { error: "no-md" };
      md.querySelectorAll('span[style*="-9999px"], [aria-hidden="true"].katex-html').forEach((n) => n.remove());
      md.querySelectorAll(".katex").forEach((k) => {
        const tex = k.querySelector('annotation[encoding="application/x-tex"]');
        if (tex) { const s = document.createElement("span"); s.textContent = tex.textContent; k.replaceWith(s); }
      });
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
          if (tag === "table") { push("table", child.innerText.trim()); continue; }
          if (tag === "img") { push("img", child.getAttribute("src")); continue; }
          if (tag === "blockquote") { push("p", child.innerText.trim()); continue; }
          walk(child);
        }
      };
      walk(md);
      const firstText = md.firstChild && md.firstChild.nodeType === 3 ? md.firstChild.textContent.trim() : "";
      if (firstText) blocks.unshift({ lang: "p", text: firstText });

      const txt = left.innerText || "";
      const scoreM = txt.match(/分数\s*(\d+)/);
      const authorM = txt.match(/作者\s*([^\n]+)/);
      const unitM = txt.match(/单位\s*([^\n]+)/);
      const restrictM = txt.match(/代码长度限制[\s\S]*?栈限制\s*\d+\s*KB/);
      const titleM = txt.match(/^(\d+-\d+)\s+(.+)/m);
      return {
        score: scoreM ? scoreM[1] : null,
        author: authorM ? authorM[1].trim() : null,
        unit: unitM ? unitM[1].trim() : null,
        restrict: restrictM ? restrictM[0].replace(/\s*\n\s*/g, " ") : null,
        blocks,
      };
    });

    const record = { id: pid, ...data };
    done.push(record);
    console.log(`${set.name} ${i + 1}/${set.order.length} ${pid} blocks=${data.blocks ? data.blocks.length : "ERR " + data.error}`);
    await fs.writeFile(outPath, JSON.stringify({ set, results: done }, null, 2));
  }
}
console.log("BATCH DONE");