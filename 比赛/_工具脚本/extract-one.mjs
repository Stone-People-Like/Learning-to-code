// 单题提取验证
const fs = await import("node:fs/promises");
const task = await claimTaskSpace(2);
const page = task.page("p1");

const url = "https://pintia.cn/problem-sets/2109431928702738432/exam/problems/type/7?problemSetProblemId=2109431928723709952";
await page.goto(url);
await page.waitForTimeout(3000);

const data = await page.evaluate(() => {
  const left = document.querySelector("div.left_TFoYO") || document.querySelector("main");
  const md = left?.querySelector("div.rendered-markdown");
  if (!md) return { error: "no markdown" };
  const root = md.closest("div.bg-bg-base") || md.parentElement;

  // 标题与分数
  const headerText = left.querySelector("div.space-y-4")?.innerText || "";
  const titleEl = left.querySelector("h1, h2");
  const meta = left.innerText.match(/分数\s*(\d+)/);

  // 提取代码块文本
  const blocks = [];
  const walk = (el) => {
    for (const child of el.children) {
      const tag = child.tagName.toLowerCase();
      if (child.hasAttribute && child.hasAttribute("data-code")) {
        const lang = child.getAttribute("data-lang");
        const lines = [...child.querySelectorAll(".cm-content .cm-line")].map((l) => l.innerText);
        blocks.push({ lang, text: lines.join("\n") });
        continue;
      }
      if (tag === "pre") {
        blocks.push({ lang: "pre", text: child.innerText });
        continue;
      }
      if (tag === "h3" || tag === "h4" || tag === "h2") {
        blocks.push({ lang: "heading", text: child.innerText.trim() });
        continue;
      }
      walk(child);
    }
  };
  walk(md);

  // 纯文本版（去掉 katex-html 与隐藏作弊文本）
  const clone = md.cloneNode(true);
  clone.querySelectorAll(".katex-html, .katex-mathml, [data-code], style, script").forEach((n) => n.remove());
  clone.querySelectorAll('span[style*="-9999px"]').forEach((n) => n.remove());
  const plain = clone.innerText;

  return {
    headerText: headerText.replace(/\s+/g, " ").trim(),
    score: meta ? meta[1] : null,
    blocks,
    plain,
    html: root ? root.outerHTML.length : 0,
  };
});

console.log(JSON.stringify(data, null, 2).slice(0, 6000));