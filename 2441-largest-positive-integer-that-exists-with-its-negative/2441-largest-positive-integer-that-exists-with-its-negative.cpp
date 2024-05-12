class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int res = -1;
        
        for (int num : nums) {
            if (num != 0) {
                if (set.count(-num) > 0) {
                    res = max(res, abs(num));
                }
            }
        }
        
        return res;
    }
};