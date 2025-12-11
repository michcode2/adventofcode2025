use std::fs;

pub fn main() {
    let file = fs::read_to_string("../input10.txt").unwrap();
    let mut acc = 0;
    for line in file.lines() {
        let target_state = line
            .chars()
            .filter_map(|b| match b.to_string().as_str() {
                "." => Some(false),
                "#" => Some(true),
                _ => None,
            })
            .collect::<Vec<bool>>();

        let button_effects = line
            .split("(")
            .map(|data_string| {
                let mut only_digits = data_string.to_string();
                only_digits = only_digits.trim_end_matches(|c| c != ')').to_string();
                only_digits.pop();
                only_digits
            })
            .filter(|s| s.len() > 0)
            .map(|numbers| {
                let splitted = numbers.split(",");
                splitted
                    .map(|num| num.parse::<u64>().unwrap())
                    .collect::<Vec<u64>>()
            })
            .collect::<Vec<Vec<u64>>>();

        let apply_number = |input: u64| {
            let mut state = vec![false; target_state.len()];
            let mut number_set = 0;
            for i in 0..button_effects.len() {
                if input & 1 << i > 0 {
                    //bitwise, checks if a certain bit is set in the number

                    number_set += 1;
                    for j in 0..button_effects[i].len() {
                        state[button_effects[i][j] as usize] =
                            !state[button_effects[i][j] as usize];
                    }
                }
            }

            if state == target_state {
                return Some(number_set);
            }
            return None;
        };

        let mut blah: Vec<i32> = vec![];

        for i in 0..=2_u64.pow(button_effects.len() as u32 + 1) {
            if let Some(n) = apply_number(i) {
                blah.push(n);
            }
        }
        blah.sort();
        acc += blah[0];
    }
    println!("{}", acc);
}
