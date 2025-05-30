class Solution {
private:
    int dp[601][101][101];
    int solve(vector<string>& s, int i, int m, int n){
        if(i>=s.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];
        int ones = countOnes(s[i]), zeros = s[i].size() - ones, take = 0, skip = 0; 
    
        if(m >= zeros && n >= ones) take = 1 + solve(s, i+1, m-zeros, n-ones);
        skip = solve(s, i+1, m, n);

        return dp[i][m][n] = max(take, skip);
    }

    int countOnes(string &s){
        int cnt = 0;
        for(char &c : s) if(c=='1') cnt++;
        return cnt;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(strs, 0, m, n);
    }
};