class Solution {
    vector<vector<int>> res;
    
    void combination(const vector<int>& candidates, vector<int> cur, int target, int sum, int i){
        if(sum == target){
            res.push_back(cur);
            return;
        }
        
        if(sum > target || i >= candidates.size()) return;
        
        for(int j = i; j < candidates.size(); ++j){
            if(j > i && candidates[j] == candidates[j-1]) continue; 
            cur.push_back(candidates[j]);
            combination(candidates, cur, target, sum + candidates[j], j + 1);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        combination(candidates, {}, target, 0, 0);
        return res;
    }
};
