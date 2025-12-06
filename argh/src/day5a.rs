use std::fs;

pub fn main() {
    let file = fs::read_to_string("../input5.txt").unwrap();
    let mut fresh_ids: Vec<(usize, usize)> = vec![];
    let mut acc = 0;

    for line in file.lines() {
        if line.len() == 0 {
            println!("evaluating db");
            continue;
        }
        let values = line
            .split("-")
            .map(|s| s.parse().unwrap())
            .collect::<Vec<usize>>();
        if values.len() == 2 {
            fresh_ids.push((values[0], values[1]));
        }
        if values.len() == 1 {
            for pair in fresh_ids.iter() {
                if pair.0 <= values[0] && pair.1 >= values[0] {
                    acc += 1;
                    break;
                }
            }
        }
    }
    println!("{}", acc)
}
