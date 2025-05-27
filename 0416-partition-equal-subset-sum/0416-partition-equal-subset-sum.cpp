class Solution {
private:
    int dp[201][20001];
    bool solve(vector<int> &n, int i, int sum){
        if(sum == 0) return true;
        if(i>=n.size()) return false;
        if(dp[i][sum] != -1) return dp[i][sum];


        int take = n[i]<=sum? solve(n, i+1, sum-n[i]) : false;
        int skip = solve(n, i+1, sum);

        return dp[i][sum] = take || skip;
    }
public:
    bool canPartition(vector<int>& nums) {
       int sum = accumulate(nums.begin(), nums.end(), 0);
       if(sum%2 != 0) return false;  
       memset(dp, -1, sizeof(dp));

       return solve(nums, 0, sum/2);
    }
};