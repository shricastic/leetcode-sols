/*
 * @lc app=leetcode id=125 lang=java
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(String s) {
    
        String str = s.replaceAll("[^a-zA-Z0-9]","").toLowerCase();
        
        int left = 0;
        int right = str.length()-1;

        while(left<right){
            if(str.charAt(right)!=str.charAt(left)){
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
}
// @lc code=end

