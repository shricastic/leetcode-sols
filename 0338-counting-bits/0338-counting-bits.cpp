class Solution {
private:
    int count(int n, vector<int>& dp){
        if(n <= 1) return n;
        
        if(dp[n] != -1) return dp[n];
        return dp[n] = count(n/2, dp) + n%2;
    }
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, -1), res(n+1);
        
        for(int i=0 ; i<=n ; i++) res[i] = count(i, dp);
        
        return res;
    }
};