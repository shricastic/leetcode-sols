class Solution {
private:
    vector<vector<int>> res;
    void permute(vector<int>& nums, vector<int> cur, vector<bool> used, int i){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }

        for(int i=0 ; i<nums.size() ; i++){
            if(used[i]) continue;
            
            used[i] = true;
            cur.push_back(nums[i]);
            
            permute(nums, cur, used, i);

            used[i] = false;
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        permute(nums, {}, used, 0);
        return res;
    }
};