class Solution {
private:
    vector<vector<int>> res;
    
    void combination(vector<int>& candidates, vector<int> cur, int target, int sum, int i){
        if(sum==target){
            res.push_back(cur);
            return;
        }
        
        if(sum>target || i >= candidates.size()) return;
        
        combination(candidates, cur, target, sum, i+1);
        
        cur.push_back(candidates[i]);
        combination(candidates, cur, target, sum+candidates[i], i);    
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combination(candidates, {}, target,0, 0);
        return res;
    }
};