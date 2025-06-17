class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
        sort(i.begin(), i.end());
        vector<vector<int>> res;

        for(auto v : i){
            if(res.empty() || res.back()[1]<v[0]) res.push_back(v);
            else res.back()[1] = max(v[1], res.back()[1]);
        }

        return res;
    }
};