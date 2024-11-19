impl Solution {
    pub fn maximum_subarray_sum(nums: Vec<i32>, k: i32) -> i64 {
        let (mut f, mut res, mut sum, mut j) = ([0; 100_001], 0, 0, 0);
        for (i, &n) in nums.iter().enumerate() {
            while i - j + 1 > k as usize || f[n as usize] > 0 {
                sum -= nums[j] as i64; f[nums[j] as usize] -= 1; j += 1
            }
            sum += n as i64; f[n as usize] += 1;
            if i - j + 1 == k as usize { res = res.max(sum) }
        }; res
    }
}
