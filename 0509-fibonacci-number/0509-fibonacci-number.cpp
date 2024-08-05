class Solution {
private:
    int fibdp(int n, vector<int> &dp){
        if(n<2) return n;
        
        if(dp[n] != -1) return dp[n];
        dp[n] = fibdp(n-1, dp) + fibdp(n-2, dp);
        
        return dp[n];
    }
    
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return fibdp(n, dp);
    }
};