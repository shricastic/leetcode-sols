class Solution {
private:
    int MOD = 1e9+7;
    int dp[31][1001];
    int solve(int n, int k, int t){
        if(t<0) return 0;
        if(n==0) return t==0;

        if(dp[n][t] != -1) return dp[n][t];

        int ways = 0;
        for(int i = 1 ; i<=k ; i++){
            ways = (ways + solve(n-1, k, t-i)) % MOD;
        }

        return dp[n][t] = ways;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, target);
    }
};