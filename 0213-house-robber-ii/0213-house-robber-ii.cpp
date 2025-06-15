class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums, int i, int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int rob = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1, n);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];

        memset(dp, -1, sizeof(dp));
        int opt1 = solve(nums, 0, n-1);

        memset(dp, -1, sizeof(dp)); 
        int opt2 = solve(nums, 1, n);
        
        return max(opt1, opt2);
    }
};