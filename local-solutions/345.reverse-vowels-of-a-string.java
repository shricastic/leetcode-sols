/*
 * @lc app=leetcode id=345 lang=java
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start

import java.util.HashSet;

class Solution {
    public String reverseVowels(String s) {
        HashSet<Character> vowels = new HashSet<>(Arrays.asList('a','e','i','o','u','A','E','I','O','U'));
        StringBuilder str = new StringBuilder(s);

        int first = 0;
        int last = str.length()-1;
        while(first<last){
            if(vowels.contains(str.charAt(first)) && vowels.contains(str.charAt(last))){
                char temp = str.charAt(first);
                str.setCharAt(first, str.charAt(last));
                str.setCharAt(last, temp);
                last--;
                first++;
            }
            else if (vowels.contains(str.charAt(first))){
                last--;
            }
            else if (vowels.contains(str.charAt(last))){
                first++;
            }
            else {
                first++;
                last--;
            }
        } 

        return str.toString();
    }
}
// @lc code=end

