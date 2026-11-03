# Stone 的 Rust 学习记录

> 陆云清的个人 Rust 学习分支 — 从 `cargo new` 开始的成长之路

## 关于我

我是陆云清（Stone），正在学习 Rust 编程。当前主要通过**洛谷刷题**的方式快速上手（学习路线见 [`Rust/洛谷刷题/README.md`](Rust/洛谷刷题/README.md)），同时保留[清华大学 Rust 课程](https://lab.cs.tsinghua.edu.cn/rust/)的章节练习与作业作为参考资料。

## 教程来源

- **课程主页**：<https://lab.cs.tsinghua.edu.cn/rust/>
- **开发工具**：<https://lab.cs.tsinghua.edu.cn/rust/tools/>
- **环境配置**：<https://lab.cs.tsinghua.edu.cn/rust/setup/>

## 学习目录

```
Stone-code-Rust/
├── README.md                    # 个人学习说明
├── Rust/                        # 代码练习与作业
│   ├── 01_basic/                # 基本语法：变量、类型、函数、控制流
│   ├── 02_ownership/            # 所有权与结构化数据
│   ├── 03_stdlib/               # 标准库
│   ├── 04_generics_traits/      # 泛型、特型与生命周期
│   ├── 05_project_manage/       # 工程管理与 Cargo
│   ├── 06_concurrency/          # 并发编程
│   ├── 07_io_async/             # 输入输出与异步编程
│   ├── 08_advanced/             # 高级特性与语言综述
│   ├── 洛谷刷题/                # 洛谷题单学习路线（当前主线，271 题）
│   ├── labs/                    # 小作业
│   │   ├── lab1_textstat/       # Lab 1 文本统计（Cargo 项目骨架）
│   │   ├── lab2_test_ai/        # Lab 2 测试 AI 代码
│   │   ├── lab3_cut/            # Lab 3 重新实现 cut
│   │   └── lab4_wordle/         # Lab 4 Vibe Wordle
│   └── projects/agent/          # 大作业：Agent
└── Markdown 笔记/                # 各章对应的学习笔记
    └── Rust/
        ├── 01_basic/
        ├── 02_ownership/
        └── ...（与 Rust/ 章节一一对应）
```

## 学习路线

| 章节 | 主题 | 状态 |
|------|------|------|
| 01 | 课程介绍与基本语法 | 待开始 |
| 02 | 所有权与结构化数据 | 待开始 |
| 03 | 标准库 | 待开始 |
| 04 | 泛型、特型与生命周期 | 待开始 |
| 05 | 工程管理与其他 | 待开始 |
| 06 | 并发编程 | 待开始 |
| 07 | 输入输出与异步编程 | 待开始 |
| 08 | 高级特性与编程语言综述 | 待开始 |

### 小作业

| 作业 | 内容 | 状态 |
|------|------|------|
| Lab 1 | 文本统计 | 待开始 |
| Lab 2 | 测试 AI 代码 | 待开始 |
| Lab 3 | 重新实现 `cut` | 待开始 |
| Lab 4 | Vibe Wordle | 待开始 |

### 大作业

| 项目 | 内容 | 状态 |
|------|------|------|
| Agent | 基于 Rust 的智能体实现 | 待开始 |

## 开发环境

- **IDE**: VSCode + rust-analyzer（课程推荐）
- **工具链**: rustup / cargo / rustc
- **辅助工具**: clippy（静态检查）、rustfmt（格式化）、miri（动态检查）

### 常用命令

```bash
# 安装 / 更新工具链
rustup update

# 安装辅助组件
rustup component add clippy rustfmt

# 新建项目
cargo new hello_rust

# 编译运行
cargo run

# 检查、格式化、静态分析
cargo check
cargo fmt
cargo clippy

# 查看编译器错误详解
rustc --explain E0384
```

VSCode 推荐配置（`settings.json`）：

```json
{
  "rust-analyzer.check.command": "clippy",
  "editor.formatOnSave": true
}
```

## 学习资源

### 官方文档
- [Rust 程序设计语言（中文版）](https://kaisery.github.io/trpl-zh-cn/)
- [Rust 标准库文档](https://doc.rust-lang.org/std/)
- [Rust by Example](https://doc.rust-lang.org/rust-by-example/)
- [The Rustonomicon](https://doc.rust-lang.org/nomicon/)

### 在线学习平台
- [Rustlings 练习](https://github.com/rust-lang/rustlings)
- [LeetCode 力扣](https://leetcode.cn/)

### AI 辅助开发原则

课程明确要求：**必须自己参与开发过程，与 AI 协同，而不是把题目直接交给 AI**。

- 不使用 AI 生成作业主体代码
- 不借助 AI 翻译或伪原创以规避查重
- 不生成整篇实验报告而不理解、不修改

---

公共学习资料请查看 [`main` 分支](https://github.com/Stone-People-Like/Learning-to-code/tree/main)