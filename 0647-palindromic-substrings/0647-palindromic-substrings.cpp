class Solution {
private:
    string s;
    int dp[1001][1001];
    int solve(int i, int j){
        if(dp[i][j] != -1) return dp[i][j];
        int l = i, k = j;
        bool flag = true;
        while(i<=j){
            if(s[i]!=s[j]) {flag = false; break;}
            i++, j--;
        }
        return dp[l][k] = flag? 1 : 0;
    }
public:
    int countSubstrings(string s) {
        this-> s = s;
        int cnt = 0;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<s.size() ; i++){
            for(int j=i; j<s.size() ; j++) cnt+=solve(i, j);
        }
        
        return cnt;
    }
};