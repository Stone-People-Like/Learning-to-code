// P1001 - A+B Problem
// https://www.luogu.com.cn/problem/P1001

fn main() {
    let mut it = luogu::input();
    let a: i64 = it.next().unwrap().parse().unwrap();
    let b: i64 = it.next().unwrap().parse().unwrap();
    println!("{}", a + b);
}