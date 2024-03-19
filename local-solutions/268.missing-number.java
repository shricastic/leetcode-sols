/*
 * @lc app=leetcode id=268 lang=java
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int actualSum = 0;
        int expectedSum = ((n*n)+n)/2;
        
        for(int num:nums){
            actualSum += num;
        }

        return expectedSum-actualSum;
    }
}
// @lc code=end

