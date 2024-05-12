class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set;
        int res = -1;
        
        for (int num : nums) {
            set.insert(num);
            if (num != 0) {
                if (set.count(-num) > 0) {
                    res = max(res, abs(num));
                }
            }
        }
        
        return res;
    }
};