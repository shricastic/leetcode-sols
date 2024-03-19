/*
 * @lc app=leetcode id=136 lang=java
 *
 * [136] Single Number
 */

// @lc code=start

import java.util.HashSet;

class Solution {
    public int singleNumber(int[] nums) {
        HashSet<Integer> set = new HashSet<>();

        for (int num : nums) {
            if (!set.add(num)) {
                set.remove(num);
            }
        }

        return set.iterator().next();
    }
}



//USING HashMap
// import java.util.HashMap;
// import java.util.Map.Entry;

// class Solution {
//     public int singleNumber(int[] nums) {
//         HashMap<Integer, Integer> map  = new HashMap<>();
//         int result = 0;
//         for(int i : nums){
//             if(map.containsKey(i)){
//                 map.put(i, map.get(i)+1);
//             } else{
//                 map.put(i, 1);
//             }
//         }

//         for(Entry<Integer,Integer> entry : map.entrySet()){
//             if(entry.getValue() == 1){
//                 result = entry.getKey();
//                 break;
//             } 
//         }

//         return result;
//     }
// }
// @lc code=end

