/*
 * @lc app=leetcode id=121 lang=java
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE, maxProfit=0;
        for(int i=0 ; i<prices.length ; i++){
            if(prices[i]<minPrice) minPrice = prices[i];
            if((prices[i]-minPrice)>maxProfit) maxProfit=((prices[i]-minPrice));
        }
        return maxProfit;
     }
}
// @lc code=end

