impl Solution {
    pub fn get_maximum_xor(nums: Vec<i32>, maximum_bit: i32) -> Vec<i32> {
        let n = nums.len();
        let max_xor = (1 << maximum_bit) - 1; 
        let mut xor_sum = 0;
        let mut result = Vec::with_capacity(n);

        for &num in &nums {
            xor_sum ^= num;
        }

        for i in (0..n).rev() {
            result.push(xor_sum ^ max_xor);
            xor_sum ^= nums[i]; 
        }

        result
    }
}
