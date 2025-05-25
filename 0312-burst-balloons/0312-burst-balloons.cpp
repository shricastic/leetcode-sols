class Solution {
private:
    int dp[301][301];
    int solve(vector<int>& n, int i, int j){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxCoins = INT_MIN;

        for(int k=i ; k<=j ; k++){
            int coins = n[i-1] * n[k] * n[j+1];
            coins += solve(n, k+1, j); 
            coins += solve(n, i, k-1);
            maxCoins = max(maxCoins, coins);
        }

        return dp[i][j] = maxCoins;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 1, n - 2);
    }
};