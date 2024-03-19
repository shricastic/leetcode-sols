/*
 * @lc app=leetcode id=80 lang=java
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0;
        
        for(int i=0; i<nums.length-2; i++){
            if(nums[k] == nums[k+1]){
                if(nums[k+1] == nums[i]){
                    i++;
                    continue;
                }
            } else if(nums[k] != nums[k+1]){
                nums[i]=nums[i+1];
                k=k+1;
            }

        }

        return k+1;
    }
}
// @lc code=end

