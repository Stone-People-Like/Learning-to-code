// 第二轮：完整抓取一套题目集，输出结构化 JSON 到 /tmp
const fs = await import("node:fs/promises");

const task = await claimTaskSpace(2);
const page = task.page("p1");

const problemSetId = "2109431928702738432";

function mdFromBlocks(blocks) {
  const lines = [];
  for (const b of blocks) {
    if (b.lang === "heading") {
      lines.push(`\n### ${b.text}\n`);
    } else if (b.lang === "in" || b.lang === "out") {
      lines.push("```" + (b.lang === "in" ? "text" : "text"));
      lines.push(b.text.replace(/\n$/, ""));
      lines.push("```\n");
    } else {
      lines.push("```");
      lines.push(b.text);
      lines.push("```\n");
    }
  }
  return lines.join("\n");
}

// 打开列表页，取题目 ID 顺序
await page.goto(`https://pintia.cn/problem-sets/${problemSetId}/exam/problems`);
await page.waitForTimeout(2500);

const list = await page.evaluate(() => {
  const rows = [...document.querySelectorAll('a[href*="problemSetProblemId="]')];
  const order = [];
  for (const a of rows) {
    const m = a.getAttribute("href").match(/problemSetProblemId=(\d+)/);
    if (m && !order.includes(m[1])) order.push(m[1]);
  }
  // 表格里的标题与分数
  const tableRows = [...document.querySelectorAll("table tbody tr, table tr")];
  const meta = [];
  for (const tr of tableRows) {
    const cells = [...tr.querySelectorAll("td, th")].map((c) => c.innerText.replace(/\s+/g, " ").trim());
    if (cells.length >= 4 && /^\d+-\d+$/.test(cells[1] || "")) {
      meta.push({ no: cells[1], title: cells[2], score: cells[3] });
    }
  }
  return { order, meta };
});

console.log(JSON.stringify(list, null, 2));

const results = [];
for (let i = 0; i < list.order.length; i++) {
  const id = list.order[i];
  const url = `https://pintia.cn/problem-sets/${problemSetId}/exam/problems/type/7?problemSetProblemId=${id}`;
  await page.goto(url);
  await page.waitForTimeout(2200);

  const data = await page.evaluate(() => {
    const left = document.querySelector("div.left_TFoYO") || document.querySelector("main");
    const md = left?.querySelector("div.rendered-markdown");
    if (!md) return { error: "no markdown" };
    const root = md.closest("div.bg-bg-base") || md.parentElement;

    // 1. 移除水印/隐藏文本
    md.querySelectorAll('span[style*="-9999px"], [aria-hidden="true"].katex-html').forEach((n) => n.remove());
    // 2. katex 转 LaTeX 行内公式
    md.querySelectorAll(".katex").forEach((k) => {
      const tex = k.querySelector('annotation[encoding="application/x-tex"]');
      if (tex) {
        const span = document.createElement("span");
        span.textContent = tex.textContent;
        k.replaceWith(span);
      }
    });

    const metaText = (left.innerText || "").match(/分数\s*(\d+)/);
    const authorEl = [...left.querySelectorAll("div")].find((d) => d.innerText.startsWith("作者") && d.innerText.length < 80);

    // 遍历渲染节点
    const blocks = [];
    const push = (lang, text) => {
      if (text !== null && text !== undefined) blocks.push({ lang, text });
    };
    const walk = (el) => {
      for (const child of el.children) {
        const tag = child.tagName.toLowerCase();
        if (child.hasAttribute && child.hasAttribute("data-code")) {
          const lang = child.getAttribute("data-lang");
          const lines = [...child.querySelectorAll(".cm-content .cm-line")].map((l) => l.innerText);
          push(lang, lines.join("\n"));
          continue;
        }
        if (tag === "h2" || tag === "h3" || tag === "h4") {
          push("heading", child.innerText.trim());
          continue;
        }
        if (tag === "p") {
          push("p", child.innerText.trim());
          continue;
        }
        if (tag === "pre") {
          push("pre", child.innerText);
          continue;
        }
        if (tag === "ul" || tag === "ol") {
          push("list", child.innerText.trim());
          continue;
        }
        if (tag === "table") {
          push("table", child.innerText.trim());
          continue;
        }
        if (tag === "img") {
          push("img", child.getAttribute("src"));
          continue;
        }
        walk(child);
      }
    };
    walk(md);
    if (md.firstChild && md.firstChild.nodeType === 3 && md.firstChild.textContent.trim()) {
      blocks.unshift({ lang: "p", text: md.firstChild.textContent.trim() });
    }

    // 底部限制信息
    const restrict = (left.innerText || "").match(/代码长度限制[\s\S]*?栈限制\s*\d+\s*KB/);

    return {
      score: metaText ? metaText[1] : null,
      author: authorEl ? authorEl.innerText.replace(/\s+/g, " ").trim() : null,
      blocks,
      restrict: restrict ? restrict[0].replace(/\s*\n\s*/g, " | ") : null,
    };
  });

  const info = list.meta[i] || {};
  results.push({ id, no: info.no, title: info.title, score: info.score, ...data });
  console.log(`${i + 1}/${list.order.length} ${info.no} ${info.title} blocks=${data.blocks ? data.blocks.length : 0}`);
}

await fs.writeFile(`/tmp/pta-${problemSetId}.json`, JSON.stringify({ problemSetId, list, results }, null, 2));
console.log("saved /tmp/pta-" + problemSetId + ".json");
console.log("MARKDOWN_SAMPLE\n" + mdFromBlocks(results[0].blocks).slice(0, 1200));