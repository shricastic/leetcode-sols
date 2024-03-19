/*
 * @lc app=leetcode id=242 lang=java
 *
 * [242] Valid Anagram
 */

// @lc code=start
//Solution 1 using Arrays Class
// import java.util.Arrays;

// class Solution {
//     public boolean isAnagram(String s, String t) {
//         char[] sChar = s.toCharArray();
//         char[] tChar = t.toCharArray();

//         Arrays.sort(sChar);
//         Arrays.sort(tChar);

//         return Arrays.equals(sChar, tChar);
//     }
// }

class Solution{
    public boolean isAnagram(String s, String t){

        int[] count = new int[26];

        for(char c : s.toCharArray()){
            count[c-'a']++;
        }

        for(char c: t.toCharArray()){
            count[c-'a']--;
        }

        for(int a : count){
            if(a!=0) return false;
        }

        return true;
    }
}



// @lc code=end

