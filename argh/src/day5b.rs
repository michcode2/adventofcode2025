use std::fs;
use std::process::exit;

use rayon::iter::{IntoParallelIterator, ParallelIterator};

pub fn main() {
    let file = fs::read_to_string("../input5.txt").unwrap();
    let mut fresh_ids: Vec<(usize, usize)> = vec![];

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
            let lowest = fresh_ids.iter().map(|p| p.0).min().unwrap();
            let highest = fresh_ids.iter().map(|p| p.1).max().unwrap();

            let acc: usize = (lowest..=highest)
                .into_par_iter()
                .map(|i| {
                    for pair in fresh_ids.iter() {
                        if pair.0 <= i && pair.1 >= i {
                            return 1;
                        }
                    }
                    return 0;
                })
                .sum();
            println!("{}", acc);
            exit(0);
        }
    }
}
