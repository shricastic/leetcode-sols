class Solution {
private:
    int dp[10001];
    int solve(vector<int>& c, int amt){
        if (amt == 0) return 0;   
        if (amt < 0) return INT_MAX;

        if (dp[amt] != -1) return dp[amt];
    
        int ways = INT_MAX;
        for (int i = 0; i < c.size(); i++) {
            int cnt = solve(c, amt - c[i]);
            if (cnt != INT_MAX) {
                ways = min(ways, 1 + cnt);
            }
        }
    
        return dp[amt] = ways;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        memset(dp, -1, sizeof(dp));        
        int res = solve(coins, amount);  
        return res == INT_MAX ? -1 : res;
    }
};