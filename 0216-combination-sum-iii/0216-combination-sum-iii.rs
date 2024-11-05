impl Solution {
    pub fn combination(res: &mut Vec<Vec<i32>>, nums: &Vec<i32>, cur: Vec<i32>, i: usize, sum: i32, k: usize, n: i32){
        if sum == n && cur.len() == k { res.push(cur); return; }
        if cur.len()>k || sum>=n || i>=nums.len() { return };
        
        Self::combination(res, nums, cur.clone(), i+1, sum, k, n);
        let mut new_cur = cur.clone();
        new_cur.push(nums[i]);
        Self::combination(res, nums, new_cur, i+1, sum+nums[i], k, n);
    }
    
    pub fn combination_sum3(k: i32, n: i32) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        let nums: Vec<i32> = vec![1, 2, 3, 4, 5, 6, 7, 8, 9];
        
        Self::combination(&mut res, &nums, vec![], 0, 0, k as usize, n);
        res
    }
}