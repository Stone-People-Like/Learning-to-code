// 第一轮：抓取指定题目集下所有题目的完整内容，返回结构化 JSON
const fs = await import("node:fs/promises");

const spaceId = 2;
const task = await claimTaskSpace(spaceId);
const page = task.page("p1");

const problemSetId = process.argv[2] || "2109431928702738432";

// 打开题目集，进入题目列表
await page.goto(`https://pintia.cn/problem-sets/${problemSetId}/overview`);
await page.waitForTimeout(2000);

// 若未开始答题，点击开始
const started = await page.evaluate(() => /开始答题/.test(document.body.innerText));
if (started) {
  const btn = await page.evaluate(() => {
    const b = [...document.querySelectorAll("button")].find((x) => x.innerText.trim() === "开始答题");
    if (!b) return null;
    b.click();
    return true;
  });
  await page.waitForTimeout(2500);
}

// 进入题目列表页
await page.goto(`https://pintia.cn/problem-sets/${problemSetId}/exam/problems`);
await page.waitForTimeout(2500);

// 抓取题型分组（编程题 / 函数题 / 选择填空等）与题号列表
const groups = await page.evaluate(() => {
  const seen = [];
  const anchors = [...document.querySelectorAll('a[href*="/exam/problems/type/"]')];
  for (const a of anchors) {
    const typeMatch = a.getAttribute("href").match(/type\/(\d+)/);
    if (!typeMatch) continue;
    const text = a.innerText.trim().split("\n");
    const label = text[0];
    const counts = a.innerText.match(/(\d+)\s*\/\s*(\d+)/);
    if (!seen.find((s) => s.type === typeMatch[1])) {
      seen.push({ type: typeMatch[1], label, done: counts ? counts[1] : null, total: counts ? counts[2] : null });
    }
  }
  // 题号快捷入口
  const ids = [];
  for (const a of document.querySelectorAll('a[href*="problemSetProblemId="]')) {
    const m = a.getAttribute("href").match(/problemSetProblemId=(\d+)/);
    if (m && !ids.includes(m[1])) ids.push(m[1]);
  }
  return { groups: seen, ids };
});

console.log(JSON.stringify(groups, null, 2));
await fs.writeFile(`/tmp/pta-groups-${problemSetId}.json`, JSON.stringify(groups, null, 2));