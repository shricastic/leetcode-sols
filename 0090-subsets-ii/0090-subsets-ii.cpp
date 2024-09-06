class Solution {
private:
    vector<vector<int>> res;
    
    void subset(const vector<int>& nums, vector<int> cur, int i){
        res.push_back(cur);
        
        for(int j = i; j < nums.size(); ++j){
            if(j > i && nums[j] == nums[j-1]) continue; 
            cur.push_back(nums[j]);
            subset(nums, cur, j + 1);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        subset(nums, {}, 0);
        return res;
    }
};
