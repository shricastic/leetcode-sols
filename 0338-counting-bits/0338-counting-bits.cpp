class Solution {
private:
    int count(int n, vector<int>& dp){
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        if(dp[n] != -1) return dp[n];
        dp[n] = count(n/2, dp) + n%2;
        return dp[n];
    }
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, -1), res(n+1);
        
        for(int i=0 ; i<=n ; i++) res[i] = count(i, dp);
        
        return res;
    }
};