class Solution {
private:
    int dp[10001];
    int solve(vector<int>& n, int i){
        if(i >= n.size() - 1) return 0;
        if(dp[i] != -1) return dp[i];
    
        int minSteps = INT_MAX;
        for(int j = i + 1; j <= i + n[i] && j < n.size(); j++){
            int steps = solve(n, j);
            if (steps != INT_MAX && steps + 1 < minSteps) {
                minSteps = steps + 1;
            }
        }
    
        return dp[i] = minSteps;
    }
public:
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};