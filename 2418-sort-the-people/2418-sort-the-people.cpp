class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> map;
        
        for(int i = 0 ; i < names.size() ; i++){
            map[heights[i]] = names[i];
        }
        
        vector<string> res;
        
        for(auto it : map){
            res.insert(res.begin(), it.second);
        }
        
        return res;
    }
};