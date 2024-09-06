class Solution {
private:
    vector<vector<int>> v;
    
    void findSubsets(vector<int>& nums, vector<int> res, int i){
        if(i==nums.size()){
            v.push_back(res);
            return;
        }
        
        findSubsets(nums, res, i+1);
        
        res.push_back(nums[i]);
        findSubsets(nums, res, i+1);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        findSubsets(nums, {}, 0);
        return v;
    }
};