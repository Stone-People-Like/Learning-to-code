# 洛谷刷题工作区

所有题目代码都在 `src/bin/` 下，一题一个文件，一个 Cargo 项目统一管理。

## 常用命令

```bash
cd luogu

# 运行某题（从文件读输入）
cargo run --bin P1001 < in.txt

# 手动输入后 Ctrl-D 结束
cargo run --bin P1001

# 只检查编译
cargo check --bin P1001

# 编译全部
cargo build
```

## 输入工具

`src/lib.rs` 提供了两个函数：

```rust
// 一次性读完所有输入，按空白切分
let mut it = luogu::input();
let n: usize = it.next().unwrap().parse().unwrap();
let m: i64 = it.next().unwrap().parse().unwrap();

// 读一整行，保留空格、去掉换行
let line = luogu::read_line();
```

## 新建一道题

```bash
cd luogu/src/bin
vi P1008.rs
```

文件头建议保留题号和链接，方便回看。

## 目录说明

题目分类目录在 `../Rust/洛谷刷题/`，每题单有一个 `README.md` 记录题单与进度。