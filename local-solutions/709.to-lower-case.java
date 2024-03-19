/*
 * @lc app=leetcode id=709 lang=java
 *
 * [709] To Lower Case
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public String toLowerCase(String s) {
        char[] arr = s.toCharArray();

        for(int i=0 ; i<arr.length ; i++){
            if(arr[i] >= 'A' && arr[i] <= 'Z'){
                arr[i] = (char) (arr[i] + ('a'-'A'));
            }
        }

        return String.valueOf(arr);        
    }
}
// @lc code=end

