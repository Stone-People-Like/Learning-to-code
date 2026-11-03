# textstat

## 运行

```bash
cargo run < input.txt
```

从标准输入读取全部内容，输出四行：

```
lines: <行数> words: <词数> chars: <字符数> longest: <最长一行的长度>
```

## 约束

- Rust edition 2024
- 不使用任何第三方 crate
- 统计规则见课程 Lab 1 文档：<https://lab.cs.tsinghua.edu.cn/rust/labs/lab1/>