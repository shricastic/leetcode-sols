use std::cmp;
use std::vec::Vec;

impl Solution {
    pub fn prime_sub_operation(nums: Vec<i32>) -> bool {
        let max_element = *nums.iter().max().unwrap();
        if max_element == 1 { return true; }

        
        let mut sieve = vec![true; (max_element + 1) as usize];
        sieve[0] = false;
        sieve[1] = false;
        let limit = (max_element as f64).sqrt() as i32 + 1;

        for i in 2..=limit {
            if sieve[i as usize] {
                let mut j = i * i;
                while j <= max_element {
                    sieve[j as usize] = false;
                    j += i;
                }
            }
        }

        let mut curr_value = 1;
        let mut i = 0;
        
        while i < nums.len() {
            let difference = nums[i] - curr_value;

            if difference < 0 {
                return false;
            }

            if sieve[difference as usize] || difference == 0 {
                i += 1;
                curr_value += 1;
            } else {
                curr_value += 1;
            }
        }

        true
    }
}
