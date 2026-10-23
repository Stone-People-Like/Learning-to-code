const fs = await import("node:fs/promises");
const index = JSON.parse(await fs.readFile("/tmp/pta-index.json", "utf8"));

const sets = [];
for (const s of index) {
  const d = JSON.parse(await fs.readFile(`/tmp/pta-sets/${s.id}.json`, "utf8"));
  const norm = d.results.map((r) =>
    (r.blocks || []).map((b) => b.text).join("|").replace(/\s+/g, "").slice(0, 200)
  );
  sets.push({ id: s.id, name: s.name, norm, meta: d.results.map((r) => s.meta ? null : null) });
}

// 两两比较相似度
const out = [];
for (let i = 0; i < sets.length; i++) {
  for (let j = i + 1; j < sets.length; j++) {
    const a = sets[i].norm, b = sets[j].norm;
    const n = Math.min(a.length, b.length);
    let same = 0;
    for (let k = 0; k < n; k++) if (a[k] === b[k]) same++;
    const pct = n ? Math.round((same / n) * 100) : 0;
    if (pct >= 50) out.push({ a: sets[i].name, b: sets[j].name, same, total: n, pct });
  }
}
console.log(JSON.stringify(out, null, 2));

// 每套的题目标题
for (const s of index) {
  const d = JSON.parse(await fs.readFile(`/tmp/pta-sets/${s.id}.json`, "utf8"));
  console.log("\n== " + s.name + " (" + s.id + ")");
  Object.entries(s.meta).forEach(([no, m]) => console.log(`  ${no} ${m.title} (${m.score})`));
}