class Solution {
private:
    int dp[31][3001];
    int solve(vector<int>& st, int idx, int a, int b){
        int diff = abs(a-b);
        if(idx == st.size()) return diff;
        if(dp[idx][diff] != -1) return dp[idx][diff];

        int k = min(solve(st, idx+1, a+st[idx], b), solve(st, idx+1, a, b+st[idx]));

        return dp[idx][diff] = k;
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        return solve(stones, 0, 0, 0); 
    }
};