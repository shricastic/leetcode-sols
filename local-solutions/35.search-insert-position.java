/*
 * @lc app=leetcode id=35 lang=java
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
    public int searchInsert(int[] nums, int target) {
        int start = 0, end = nums.length-1; 
        int mid = 0;

        while(start<=end){
            mid = (start+end)/2;

            if(nums[mid]>target){
                end = mid-1;
            } else if(nums[mid]<target){
                start = mid+1;
            } else{
                return mid;
            }

        }
        return start;
        
    }
}
// @lc code=end

