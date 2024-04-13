class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        vector<int> res;
        
        for (int i = 1; i <= nums.size(); ++i) {
            if (numSet.find(i) == numSet.end()) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};
