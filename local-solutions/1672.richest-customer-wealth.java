/*
 * @lc app=leetcode id=1672 lang=java
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start
class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxwealth = Integer.MIN_VALUE;
        int current = 0;

        for(int i=0 ; i<accounts.length ; i++){
            current = 0;
            for(int j=0 ; j<accounts[i].length ; j++){
                current += accounts[i][j];
            }
            if(current>maxwealth) maxwealth = current;
        }
        
        return maxwealth;
    }
}
// @lc code=end

