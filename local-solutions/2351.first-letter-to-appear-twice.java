/*
 * @lc app=leetcode id=2351 lang=java
 *
 * [2351] First Letter to Appear Twice
 */

// @lc code=start

import java.util.HashSet;

class Solution {
    public char repeatedCharacter(String s) {
        HashSet<Character> set = new HashSet<>();

        for(char c : s.toCharArray()){
            if(!set.add(c)){
                return c;
            }
        }

        return ' ';

    }
}
// @lc code=end

