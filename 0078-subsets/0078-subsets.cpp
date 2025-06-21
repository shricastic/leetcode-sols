class Solution {
private:
    vector<vector<int>> res;
    vector<int> nums;
    void solve(vector<int> cur, int n, int i){
        if(cur.size() == n){
            res.push_back(cur);
            return;
        }
        if(i>=nums.size()) return;


        solve(cur, n, i+1);
        cur.push_back(nums[i]);
        solve(cur, n, i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        for(int i=0 ; i<=nums.size() ; i++){
            solve({}, i, 0);
        }
        return res; 
    }
};