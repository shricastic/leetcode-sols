class Solution {
private:
    int dp[5001][301];
    int solve(vector<int>& c, int amt, int idx){
        if(amt==0) return 1;
        if(amt<0 || idx == c.size()) return 0;

        if(dp[amt][idx] != -1) return dp[amt][idx];

        int ways = solve(c, amt, idx+1) + solve(c, amt-c[idx], idx);

        return dp[amt][idx] = ways;
    }
public:
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(coins, amount, 0); 
    }
};