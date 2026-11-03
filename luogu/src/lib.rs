//! 刷题公共工具：统一的快速输入读取。

use std::io::{self, Read};

/// 一次性读完整个标准输入，返回按空白切分后的词迭代器。
///
/// 用法：
/// ```
/// let mut it = luogu::input();
/// let n: usize = it.next().unwrap().parse().unwrap();
/// ```
pub fn input() -> std::str::SplitWhitespace<'static> {
    let mut buf = String::new();
    io::stdin().read_to_string(&mut buf).expect("读取输入失败");
    // 故意泄漏，方便返回 'static 的迭代器；每次运行只泄漏一次，可忽略
    Box::leak(buf.into_boxed_str()).split_whitespace()
}

/// 读入一行（去掉行尾换行符），用于需要保留空格的字符串题。
pub fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).expect("读取输入失败");
    line.trim_end_matches(['\n', '\r']).to_string()
}