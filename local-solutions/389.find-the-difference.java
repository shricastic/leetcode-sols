/*
 * @lc app=leetcode id=389 lang=java
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
    public char findTheDifference(String s, String t) {
        int[] count = new int[26];

        for(char c : t.toCharArray()){
            count[c-'a']++;
        }

        for(char c : s.toCharArray()){
            count[c-'a']--;
        }

        for(int i=0; i<count.length ; i++){
            if(count[i]>0) return (char)(i+'a') ;
        }

        return ' ';
    }
}
// @lc code=end

