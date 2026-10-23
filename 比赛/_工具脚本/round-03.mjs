// 第三轮：抓取全部 8 个题目集
const fs = await import("node:fs/promises");
const task = await claimTaskSpace(2);
const page = task.page("p1");

const sets = [
  { id: "2109431928702738432", name: "2025年杭州师范大学程序设计基础多校联考第一场" },
  { id: "2109427820033847296", name: "2023学年秋学期程序设计基础联考第一场" },
  { id: "2109427777046421504", name: "2024年杭州师范大学程序设计基础课程多校联考第一场(软件技术265)" },
  { id: "2109427710507986944", name: "2022-2023 学年秋学期程序设计基础联考第一场" },
  { id: "2113158398785671168", name: "2024年杭州师范大学程序设计基础课程多校联考第一场(2026邀请)" },
  { id: "2110206040450867200", name: "2025第一次月考" },
  { id: "2111978103382949888", name: "2024-2025学年第一学期《程序设计基础》期末考试" },
  { id: "2111977615346335744", name: "2023-2024学年第一学期《程序设计基础》期末考试" },
];

const all = [];

for (const set of sets) {
  await page.goto(`https://pintia.cn/problem-sets/${set.id}/overview`);
  await page.waitForTimeout(1800);

  const needStart = await page.evaluate(() => {
    const b = [...document.querySelectorAll("button")].find((x) => x.innerText.trim() === "开始答题");
    if (b) { b.click(); return true; }
    return false;
  });
  if (needStart) await page.waitForTimeout(2500);

  await page.goto(`https://pintia.cn/problem-sets/${set.id}/exam/problems`);
  await page.waitForTimeout(2200);

  const types = await page.evaluate(() => {
    const outList = [];
    for (const a of document.querySelectorAll('a[href*="/exam/problems/type/"]')) {
      const m = a.getAttribute("href").match(/type\/(\d+)/);
      if (!m) continue;
      const lb = a.innerText.trim().split("\n")[0];
      if (!outList.find((o) => o.type === m[1])) outList.push({ type: m[1], label: lb });
    }
    const orderIds = [];
    for (const a of document.querySelectorAll('a[href*="problemSetProblemId="]')) {
      const mm = a.getAttribute("href").match(/problemSetProblemId=(\d+)/);
      if (mm && !orderIds.includes(mm[1])) orderIds.push(mm[1]);
    }
    const metaMap = {};
    for (const tr of document.querySelectorAll("table tr")) {
      const cells = [...tr.querySelectorAll("td, th")].map((c) => c.innerText.replace(/\s+/g, " ").trim());
      if (cells.length >= 4 && /^\d+-\d+$/.test(cells[1] || "")) metaMap[cells[1]] = { title: cells[2], score: cells[3] };
    }
    return { types: outList, order: orderIds, meta: metaMap };
  });

  console.log(`[${set.name}] types=${JSON.stringify(types.types)} count=${types.order.length}`);
  all.push({ ...set, ...types });

  await fs.writeFile(`/tmp/pta-index.json`, JSON.stringify(all, null, 2));
}

console.log("DONE index saved");