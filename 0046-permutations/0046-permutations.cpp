class Solution {
private:
    vector<vector<int>> res;
    
    void permutations(vector<int>& nums, vector<int>& cur) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (find(cur.begin(), cur.end(), nums[i]) != cur.end()) continue;
            cur.push_back(nums[i]);
            permutations(nums, cur);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        permutations(nums, cur);
        return res;
    }
};