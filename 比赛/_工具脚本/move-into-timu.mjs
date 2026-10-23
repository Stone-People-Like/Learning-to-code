// 把每套题库的 7-*.md 移入新建的「题目」文件夹，并修正目录内链接
const fs = await import("node:fs/promises");
const path = await import("node:path");

const BASE = "/Users/admin/Documents/Desktop Project/Learing-to-code/比赛";
const entries = await fs.readdir(BASE, { withFileTypes: true });

for (const e of entries) {
  if (!e.isDirectory() || e.name.startsWith("_") || e.name.startsWith(".")) continue;
  const dir = path.join(BASE, e.name);
  const files = await fs.readdir(dir);
  const mds = files.filter((f) => /^\d+-\d+-.*\.md$/.test(f));
  if (!mds.length) {
    console.log(`跳过 ${e.name}（无题目 md）`);
    continue;
  }

  const target = path.join(dir, "题目");
  await fs.mkdir(target, { recursive: true });
  for (const f of mds) {
    await fs.rename(path.join(dir, f), path.join(target, f));
  }

  // 修正目录文件里的相对链接
  const tocPath = path.join(dir, "00-题目目录.md");
  let toc = "";
  try {
    toc = await fs.readFile(tocPath, "utf8");
  } catch {
    console.log(`  ${e.name}: 无 00-题目目录.md`);
  }
  if (toc) {
    // 链接形如 [name](urlencoded.md) -> [name](%E9%A2%98%E7%9B%AE/urlencoded.md)
    toc = toc.replace(/\]\(([^)\/]+\.md)\)/g, (m, p) => `](%E9%A2%98%E7%9B%AE/${p})`);
    // 说明行补充位置
    if (!toc.includes("题目文件位于")) {
      toc = toc.replace(
        /^## 题目目录\n/m,
        `> 题目文件位于本目录下的 \`题目/\` 文件夹。\n\n## 题目目录\n`
      );
    }
    await fs.writeFile(tocPath, toc, "utf8");
  }
  console.log(`${e.name}: ${mds.length} 个题目文件已移入 题目/`);
}
console.log("DONE");