class Solution {
private:
    int dp[1001][1001];
    int solve(vector<int>& s, int si, int ei, int sum){
        if(si==ei || si>ei) return 0;
        if(dp[si][ei] != -1) return dp[si][ei];

        int choose_si = sum - s[si] - solve(s, si+1, ei, sum - s[si]);
        int choose_ei = sum - s[ei] - solve(s, si, ei-1, sum - s[ei]);

        return dp[si][ei] = max(choose_si, choose_ei);
    }
public:
    int stoneGameVII(vector<int>& stones) {
        int sum = 0;
        for(int &s: stones) sum+=s;
        memset(dp, -1, sizeof(dp));
        return solve(stones, 0, stones.size()-1, sum); 
    }
};