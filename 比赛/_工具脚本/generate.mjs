// 生成 Markdown 题库文件
const fs = await import("node:fs/promises");
const BASE = "/Users/admin/Documents/Desktop Project/Learing-to-code/比赛";

const index = JSON.parse(await fs.readFile("/tmp/pta-index.json", "utf8"));

// 8 份线上题库 -> 6 个本地目录（已按用户确认的合并规则）
const plan = [
  { id: "2110206040450867200", dir: "2025 第一次月考", aliasIds: ["2109431928702738432"] },
  { id: "2109427820033847296", dir: "2023学年秋学期程序设计基础联考第一场", aliasIds: [] },
  { id: "2109427777046421504", dir: "2024年杭州师范大学程序设计基础课程多校联考第一场", aliasIds: ["2113158398785671168"] },
  { id: "2109427710507986944", dir: "2022学年秋学期程序设计基础联考第一场", aliasIds: [] },
  { id: "2111978103382949888", dir: "2024-2025学年第一学期《程序设计基础》期末考试", aliasIds: [] },
  { id: "2111977615346335744", dir: "2023-2024学年第一学期《程序设计基础》期末考试", aliasIds: [] },
];

const safe = (s) => s.replace(/[\/\\:*?"<>|]/g, "_").trim();

function renderBlocks(blocks) {
  const out = [];
  for (const b of blocks) {
    if (b.lang === "heading") {
      out.push(`\n**${b.text}**\n`);
    } else if (b.lang === "in") {
      out.push("```text\n" + b.text.replace(/\n$/, "") + "\n```\n");
    } else if (b.lang === "out") {
      out.push("```text\n" + b.text.replace(/\n$/, "") + "\n```\n");
    } else if (b.lang === "p") {
      out.push(b.text + "\n");
    } else if (b.lang === "list") {
      out.push(b.text + "\n");
    } else if (b.lang === "table") {
      out.push("\n" + b.text + "\n");
    } else if (b.lang === "pre") {
      out.push("```\n" + b.text + "\n```\n");
    } else if (b.lang === "img") {
      out.push(`![题图](${b.text})\n`);
    }
  }
  return out.join("\n");
}

const summary = [];

for (const p of plan) {
  const set = index.find((s) => s.id === p.id);
  const data = JSON.parse(await fs.readFile(`/tmp/pta-sets/${p.id}.json`, "utf8"));
  const dir = `${BASE}/${p.dir}`;
  await fs.mkdir(dir, { recursive: true });

  let totalScore = 0;
  const lines = [];
  lines.push(`# ${p.dir}\n`);
  lines.push(`- 题目集 ID：\`${p.id}\``);
  if (p.aliasIds.length) lines.push(`- 同内容题目集 ID：${p.aliasIds.map((a) => "`" + a + "`").join("、")}（内容完全一致，已合并）`);
  lines.push(`- 题目数量：${data.results.length}`);
  lines.push(`- 抓取时间：2026-10-23`);
  lines.push(`- 来源：PTA 拼题A（pintia.cn）\n`);
  lines.push(`## 题目目录\n`);
  lines.push(`| 题号 | 标题 | 分数 | 文件 |`);
  lines.push(`| --- | --- | --- | --- |`);

  const metaKeys = Object.keys(set.meta);
  const toc = [];
  for (let ri = 0; ri < data.results.length; ri++) {
    const r = data.results[ri];
    const no = r.no || metaKeys[ri] || `7-${ri + 1}`;
    const meta = set.meta[no] || {};
    const title = meta.title || "未命名";
    const score = meta.score || r.score || "-";
    totalScore += Number(score) || 0;
    const fname = `${no}-${safe(title)}.md`;
    toc.push({ no, title, score, fname, rec: r });

    const md = [];
    md.push(`# ${no} ${title}\n`);
    md.push(`| 项目 | 内容 |`);
    md.push(`| --- | --- |`);
    md.push(`| 分数 | ${score} |`);
    md.push(`| 作者 | ${r.author || "-"} |`);
    md.push(`| 单位 | ${r.unit || "-"} |`);
    md.push(`| 题目集 | ${p.dir} |`);
    md.push(`| 题目集 ID | \`${p.id}\` |`);
    md.push(`| 题目 ID | \`${r.id}\` |`);
    md.push(`| 在线地址 | https://pintia.cn/problem-sets/${p.id}/exam/problems/type/7?problemSetProblemId=${r.id} |\n`);
    md.push(renderBlocks(r.blocks || []));
    if (r.restrict) md.push(`\n---\n\n**限制**：${r.restrict}\n`);
    await fs.writeFile(`${dir}/${fname}`, md.join("\n"), "utf8");
  }

  for (const t of toc) {
    lines.push(`| ${t.no} | ${t.title} | ${t.score} | [${t.fname}](${encodeURI(t.fname).replace(/%2F/g, "/")}) |`);
  }
  lines.push(`\n合计：${data.results.length} 题，${totalScore} 分\n`);
  lines.push(`> 说明：题号沿用 PTA 原始编号（7-x）。本目录下若存在 1.c、2.c 等文件，为你本人的解答代码，未作改动。\n`);

  await fs.writeFile(`${dir}/00-题目目录.md`, lines.join("\n"), "utf8");
  summary.push({ dir: p.dir, count: data.results.length, score: totalScore });
  console.log(`${p.dir}: ${data.results.length} 题, ${totalScore} 分`);
}

// 比赛根目录总索引
const root = [];
root.push(`# 比赛题库总索引\n`);
root.push(`抓取时间：2026-10-23　来源：PTA 拼题A（pintia.cn）\n`);
root.push(`| 题库 | 题数 | 总分 |`);
root.push(`| --- | --- | --- |`);
for (const s of summary) root.push(`| [${s.dir}](${encodeURI(s.dir)}) | ${s.count} | ${s.score} |`);
root.push(`\n本地已有、线上无对应题目集的目录：\n`);
root.push(`- [蓝桥杯新生赛](%E8%93%9D%E6%A1%A5%E6%9D%AF%E6%96%B0%E7%94%9F%E8%B5%9B) — 仅本地代码，线上无此题目集\n`);
await fs.writeFile(`${BASE}/00-比赛题库总索引.md`, root.join("\n"), "utf8");
console.log("root index written");