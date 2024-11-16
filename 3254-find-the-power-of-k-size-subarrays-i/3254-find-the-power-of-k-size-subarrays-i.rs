use std::cmp;

impl Solution {
    pub fn results_array(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let length = nums.len();
        let mut result = vec![-1; length - k as usize + 1]; 

        for start in 0..=length - k as usize {
            let mut is_consecutive_and_sorted = true;

            for index in start..start + k as usize - 1 {
                if nums[index + 1] != nums[index] + 1 {
                    is_consecutive_and_sorted = false;
                    break;
                }
            }

            if is_consecutive_and_sorted {
                result[start] = nums[start + k as usize - 1];
            }
        }

        result
    }
}
