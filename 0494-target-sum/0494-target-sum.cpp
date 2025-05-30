class Solution {
private:
    int dp[21][3001];

    int solve(vector<int>& nums, int i, int t) {
        if (i == nums.size()) return t == 0 ? 1 : 0;

        if (dp[i][t + 1000] != -1) return dp[i][t + 1000];

        int sub = solve(nums, i + 1, t - nums[i]);
        int add = solve(nums, i + 1, t + nums[i]);

        return dp[i][t + 1000] = sub + add;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, target);
    }
};
