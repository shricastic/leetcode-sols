/*
 * @lc app=leetcode id=283 lang=java
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
    public void moveZeroes(int[] nums) {
        int count = 0;


        for(int num:nums){
            if(num != 0){
                nums[count]=num;
                count++;
            }
        }
        
        while(count<nums.length){
            nums[count] = 0;
            count++;
        }
    }
}
// @lc code=end

