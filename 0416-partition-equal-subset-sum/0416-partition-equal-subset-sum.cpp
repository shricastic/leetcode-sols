class Solution {
private:
    vector<int> nums;
    int dp[10001][201];
    bool solve(int i, int target){
        if(i>=nums.size() || target < 0) return false;
        if(target == 0) return true;
        if(dp[target][i] != -1) return dp[target][i];

        bool skip = solve(i+1, target);
        bool take = solve(i+1, target-nums[i]);

        return dp[target][i] = take || skip;
    }
public:
    bool canPartition(vector<int>& nums) {
        this->nums = nums;
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total%2 != 0) return false;
        
        memset(dp, -1, sizeof(dp));
        return solve(0, total/2);
    }
};