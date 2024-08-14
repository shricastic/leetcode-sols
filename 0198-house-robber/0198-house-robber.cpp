class Solution {
private:
    int steal(vector<int>& nums, vector<int>& dp, int idx){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int robcur = nums[idx] + steal(nums, dp, idx+2);
        int skipcur = steal(nums, dp, idx+1);
        
        dp[idx] = max(robcur, skipcur);
        
        return dp[idx];
    }
    
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return steal(nums, dp, 0);
    }
};