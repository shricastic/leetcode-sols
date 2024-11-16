use std::cmp;

impl Solution {
    pub fn results_array(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let length = nums.len();
        let mut res = vec![-1; length - k as usize + 1]; 

        for start in 0..=length - k as usize {
            let mut inc_sorted = true;

            for j in start..start + k as usize - 1 {
                if nums[j+1] != nums[j]+1 { inc_sorted = false; break; }
            }

            if inc_sorted { res[start] = nums[start + k as usize - 1]; }
        }

        res
    }
}
