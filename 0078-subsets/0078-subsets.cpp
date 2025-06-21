class Solution {
private:
    vector<vector<int>> res;
    vector<int> nums;
    void solve(vector<int> &cur, int i){
        if(i == nums.size()){
            res.push_back(cur);
            return;
        }

        solve(cur, i+1);
        cur.push_back(nums[i]);
        solve(cur, i+1);
        cur.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        vector<int> cur;
        solve(cur, 0);
        return res; 
    }
};