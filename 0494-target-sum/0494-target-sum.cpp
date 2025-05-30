class Solution {
private:
    int solve(vector<int>& nums, int i, int t){
        if(i == nums.size() && t==0) return 1;
        if(i>nums.size()-1) return 0;
        
        int sub = 0, add = 0;
        sub += solve(nums, i+1, t-nums[i]);
        add += solve(nums, i+1, t+nums[i]);

        return sub+add;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, target);
    }
};