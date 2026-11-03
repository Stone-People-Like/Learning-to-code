# Stone 的 Rust 学习记录

> 陆云清的个人 Rust 学习分支 — 用洛谷刷题快速上手 Rust

## 关于我

我是陆云清（Stone），正在学习 Rust 编程。学习方式是**通过洛谷题单刷题**，在做题中逐步掌握 Rust 的语法、所有权模型与标准库用法。

已经刷完的题会标记状态，卡住的地方整理成笔记，方便回头复习。

## 学习路线

完整路线见 [`Rust/洛谷刷题/README.md`](Rust/洛谷刷题/README.md)，共 18 个题单 / 271 题，按 Rust 学习曲线分为六个阶段：

| 阶段 | 内容 | 题单 | 题数 |
|------|------|------|------|
| 一 · 语法入门 | 输入输出、控制流 | 100–102 | 54 |
| 二 · 数据组织 | Vec / String / struct | 103–105 | 50 |
| 三 · 基础算法 | 模拟、排序、枚举、递推 | 106–109 | 57 |
| 四 · 稍难算法 | 贪心、二分、搜索 | 110–112 | 41 |
| 五 · 数据结构 | 线性表、树、集合、图 | 113–116 | 45 |
| 六 · 数学 | 数论与整数边界 | 117 | 24 |

## 目录结构

```
Stone-code-Rust/
├── README.md                    # 本文件
├── luogu/                       # 刷题工作区（一个 Cargo 项目，一题一个 bin）
│   ├── Cargo.toml
│   ├── README.md                # 运行方式说明
│   └── src/
│       ├── lib.rs               # 公共输入工具
│       └── bin/                 # 每道题一个文件，如 P1001.rs
└── Rust/
    └── 洛谷刷题/                # 题单与进度跟踪
        ├── README.md            # 完整路线说明
        ├── 01_语法入门/
        │   ├── 100_入门1顺序结构/
        │   └── ...
        └── 06_数学/
```

## 刷题流程

```bash
cd luogu

# 1. 打开对应题目文件
#    luogu/src/bin/P1001.rs

# 2. 本地测试
cargo run --bin P1001 < in.txt

# 3. 检查编译告警
cargo clippy --bin P1001

# 4. 提交洛谷，通过后在题单 README 里把 ⬜ 改成 ✅
```

输入工具在 `luogu/src/lib.rs`：

```rust
let mut it = luogu::input();          // 读完所有输入，按空白切分
let n: usize = it.next().unwrap().parse().unwrap();

let line = luogu::read_line();        // 读一整行，保留空格
```

## 开发环境

- **工具链**: rustup / cargo / rustc（本地已装 1.99.1）
- **crates 镜像**: USTC sparse 镜像（`~/.cargo/config.toml`）
- **IDE**: 任意支持 rust-analyzer 的编辑器（VSCode / RustRover 均可）

常用命令：

```bash
rustup update                  # 更新工具链
cargo run --bin <题号>         # 运行某题
cargo check --bin <题号>       # 检查编译
cargo clippy --bin <题号>      # 静态检查
cargo fmt                      # 格式化
rustc --explain E0384          # 查错误码详解
```

## 学习资源

### 官方文档
- [Rust 程序设计语言（中文版）](https://kaisery.github.io/trpl-zh-cn/)
- [Rust 标准库文档](https://doc.rust-lang.org/std/)
- [Rust by Example](https://doc.rust-lang.org/rust-by-example/)
- [Rustlings 练习](https://github.com/rust-lang/rustlings)

### 题目来源
- [洛谷题单列表](https://www.luogu.com.cn/training/list)
- [洛谷题库](https://www.luogu.com.cn/problem/list)

---

公共学习资料请查看 [`main` 分支](https://github.com/Stone-People-Like/Learning-to-code/tree/main)