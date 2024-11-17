use std::collections::VecDeque;

impl Solution {
    pub fn shortest_subarray(nums: Vec<i32>, k: i32) -> i32 {
        let k = k as i64; // Convert k to i64
        let mut prefix_sum = vec![0i64; nums.len() + 1];
        
        for i in 0..nums.len() {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i] as i64;
        }
        
        let mut deque = VecDeque::new();
        let mut min_len = i32::MAX;
        
        for i in 0..=nums.len() {
            while let Some(&front) = deque.front() {
                if prefix_sum[i] - prefix_sum[front] >= k {
                    min_len = min_len.min((i - front) as i32);
                    deque.pop_front();
                } else {
                    break;
                }
            }
            
            while let Some(&back) = deque.back() {
                if prefix_sum[i] <= prefix_sum[back] {
                    deque.pop_back();
                } else {
                    break;
                }
            }
            
            deque.push_back(i);
        }
        
        if min_len == i32::MAX {
            -1 // No valid subarray found
        } else {
            min_len
        }
    }
}
