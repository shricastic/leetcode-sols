class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        
        for(string str : strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            
            if(map.count(tmp)>0){
                map[tmp].push_back(str);
            } else{
                vector<string> tmpV;
                tmpV.push_back(str);
                map[tmp] = tmpV;                
            }
        }
        
        for(auto it=map.begin() ; it!=map.end() ; ++it){
            res.push_back(it->second);    
        }
        
        return res;
    }
};