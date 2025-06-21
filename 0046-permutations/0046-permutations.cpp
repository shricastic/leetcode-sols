class Solution {
private:
    vector<vector<int>> res;
    void permute(vector<int>& nums, vector<int> cur, int i){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i=0 ; i<nums.size() ; i++){
            if(find(cur.begin(), cur.end(), nums[i]) != cur.end()) continue;
            cur.push_back(nums[i]);
            permute(nums, cur, i);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums, {}, 0);
        return res;
    }
};