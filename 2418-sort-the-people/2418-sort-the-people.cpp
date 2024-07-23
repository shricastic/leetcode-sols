class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> pv;
        
        for(int i=0 ; i<names.size() ; i++){
            pv.push_back({heights[i], names[i]});
        }
        
        sort(pv.rbegin(), pv.rend());
        
        vector<string> res;
        for(auto pair : pv) res.push_back(pair.second);
        
        return res;
    }
};