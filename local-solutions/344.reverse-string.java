/*
 * @lc app=leetcode id=344 lang=java
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
    

    public void reverseString(char[] s) {
        int first = 0;
        int last = s.length-1;
        while(first<last){
            char temp = s[first];
            s[first] = s[last];
            s[last] = temp;
            
            last--;
            first++;
        }
    }
}
// @lc code=end

