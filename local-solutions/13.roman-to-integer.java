/*
 * @lc app=leetcode id=13 lang=java
 *
 * [13] Roman to Integer
 */

// @lc code=start

import java.util.HashMap;

class Solution {
    int result = 0;
    HashMap<Character, Integer> map = new HashMap<>();

    //populate the hashmap in constructor so it will be available to all objects
    public Solution() {
        map.put('M', 1000);
        map.put('D', 500);
        map.put('C', 100);
        map.put('L', 50);
        map.put('X', 10);
        map.put('V', 5);
        map.put('I', 1);
    }

    public int romanToInt(String s) {
        // Check for empty string
        if (s == null || s.length() == 0) {
            return result;
        }

        char prev = s.charAt(s.length() - 1);
        result = map.get(prev);

        for (int i = s.length() - 2; i >= 0; i--) {
            char curr = s.charAt(i);

            // Compare the values in the map
            if (map.get(curr) < map.get(prev)) {
                result -= map.get(curr); // Subtract because it's a case like IV (4) or IX (9)
            } else {
                result += map.get(curr); // Add the value of the current character
            }
            prev = curr;
        }

        return result;
    }
}

// @lc code=end

