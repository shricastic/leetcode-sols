class Solution {
private:
    int n;
    int dp[1001];
    int solve(vector<int>& nums, int t){
        if(t<0) return 0;
        if(t==0) return 1;
        int ways = 0;

        if(dp[t] != -1) return dp[t];

        for(int i=0 ; i<n ; i++){
            ways += solve(nums, t-nums[i]);
        }

        return dp[t] = ways;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        this->n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, target); 
    }
};