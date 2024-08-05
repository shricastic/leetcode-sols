class Solution {
private: 
    int minCost(int n,vector<int>& cost, vector<int> &dp){
        if(cost.size()<=n) return 0;
        
        if(dp[n] != -1) return dp[n];
        dp[n] = cost[n] + min(minCost(n+1, cost, dp), minCost(n+2, cost, dp));
        
        return dp[n];
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(minCost(0, cost, dp), minCost(1, cost, dp));
    }
};