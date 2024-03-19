/*
 * @lc app=leetcode id=169 lang=java
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
    public int majorityElement(int[] nums) {
        int majorNumber= nums[0], count = 1;
        for(int i=1; i<nums.length; i++){
            if(count==0){
                count++;
                majorNumber = nums[i];
            } else if(majorNumber == nums[i]){
                count++;
            } else count--;

        }
        return majorNumber;    
    }
}
// @lc code=end

