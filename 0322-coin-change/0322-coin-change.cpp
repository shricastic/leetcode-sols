class Solution {
private:
    int dp[1001];
    int solve(vector<int>& c, int amt){
        if (amt == 0) return 0;   
        if (amt < 0) return INT_MAX;

        if(dp[amt] != INT_MAX) return dp[amt];
    
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
        std::fill(dp, dp + 1001, INT_MAX); 
        int res = solve(coins, amount);  
        return res == INT_MAX ? -1 : res;
    }
};