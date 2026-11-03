use std::io::{self, Read};

/// 统计文本的行数、词数、字符数与最长行长度。
///
/// 规则（来自课程 Lab 1）：https://lab.cs.tsinghua.edu.cn/rust/labs/lab1/
/// - lines：末尾换行符不额外算一行；最后一行无换行符也计入；空输入为 0
/// - words：按空白切分，连续空白视为一个分隔符，不产生空词
/// - chars：各行字符数之和，不含换行符，按 `chars().count()` 计
/// - longest：最长一行的字符数，不含换行符；空输入为 0
fn main() {
    let mut input = String::new();
    io::stdin()
        .read_to_string(&mut input)
        .expect("读取标准输入失败");

    let stats = text_stat(&input);
    println!(
        "lines: {} words: {} chars: {} longest: {}",
        stats.lines, stats.words, stats.chars, stats.longest
    );
}

struct Stats {
    lines: usize,
    words: usize,
    chars: usize,
    longest: usize,
}

// TODO: 在这里实现统计逻辑
fn text_stat(input: &str) -> Stats {
    todo!("实现 Lab 1 文本统计")
}