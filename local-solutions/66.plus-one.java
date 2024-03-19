/*
 * @lc app=leetcode id=66 lang=java
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
    public int[] plusOne(int[] digits) {
        if(digits.length==0){
            return new int[]{1};
        }


        for(int i=digits.length-1 ; i>=0 ; i--){
            if( digits[i]<9 ){
                digits[i]++;
                return digits;
            } else{
                digits[i]=0;
            }
        }

        int[] newArray = new int[digits.length+1];
        newArray[0]=1;
        return newArray;
    }
}

// @lc code=end

