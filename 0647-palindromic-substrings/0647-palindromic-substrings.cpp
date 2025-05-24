class Solution {
public:
    int countSubstrings(string s) {
       int n = s.size(), cnt = 0; 

       vector<vector<bool>> dp(n+1, vector<bool>(n, false)); 
       for(int i=0 ; i<n ; i++) dp[i][i] = true, cnt++;

       for(int L=2 ; L<=n ; L++){
        for(int i=0; i+L-1<n ; i++){
            int j = i+L-1;
            if (s[i] == s[j]) {
                if (L == 2 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
       }

        return cnt;
    }
};