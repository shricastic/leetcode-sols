class Solution {
private:
    int steal(vector<int>& nums, vector<int>& dp, int start, int end){
        if(start > end) return 0;
        if(dp[start] != -1) return dp[start];
        
        int take = nums[start] + steal(nums, dp, start+2, end);
        int skip = 0 + steal(nums, dp, start+1, end);
        
        dp[start] = max(take, skip);
        
        return dp[start];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> dp1(nums.size(), -1), dp2(nums.size(), -1);
        return max(steal(nums, dp1, 1, nums.size()-1), steal(nums, dp2, 0, nums.size()-2));
    }
};