class Solution {
public:
    int numTilings(int n) {
        if (n <= 2) return n;
        
        vector<long long> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        
        for (int i = 3; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % 1000000007;
        }
        
        return dp[n];
    }
};
