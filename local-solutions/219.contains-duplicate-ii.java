/*
 * @lc app=leetcode id=219 lang=java
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Arrays.sort(nums);
        int first = nums[0];
        int last = nums[nums.length-1];

        if((first-last)<=k){
            return true;
        }

        return false;
    }
}
// @lc code=end

