import java.util.*;
/*
 * @lc app=leetcode ida=27 lang=java
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
    public int swapElement(int[] nums, int index, int val){
        for(int i=index ; i<nums.length; i++){
            if(nums[i]!=val){
                int temp=nums[index];
                nums[index]=nums[i];
                nums[i]=temp;
                return 1;
            }
        }
        return 0;
    }

    public int removeElement(int[] nums, int val) {
        int removed = 0;

        for(int i=0; i<nums.length ;i++){
            if(nums[i]==val){
                removed+=swapElement(nums, i, val);
            }
        }

        return removed;
    }
}
// @lc code=end


