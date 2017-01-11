fn main() {
    let mut input = format!("");
    std::io::stdin().read_line(&mut input);
    let t: i32 = input.trim().parse();
    for t in 1..(t+1) {
        let mut input = format!("");
        std::io::stdin().read_line(&mut input);
        let pxy = input.split_whitespace().map(|x| x.parse::<f64>());
        let p = pxy[0];
        let x = pxy[1] - 50;
        let y = pxy[2] - 50;
    }
}
