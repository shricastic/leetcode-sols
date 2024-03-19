/*
 * @lc app=leetcode id=290 lang=java
 *
 * [290] Word Pattern
 */

// @lc code=start

import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        String[] arr = s.split(" ");
        char[] pArr = pattern.toCharArray();
        
        if(arr.length != pArr.length) return false;

        HashMap<Character, String> map = new HashMap<>();

        for(int i=0 ; i<arr.length ; i++){
            if(map.containsKey(pArr[i])){
               if(!map.get(pArr[i]).equals(arr[i])){
                    return false;  
               } 
            } else{
                if(map.containsValue(arr[i])){
                    return false;
                }
                map.put(pArr[i], arr[i]);
            }
       
        }

        return true;
    }
}
// @lc code=end

