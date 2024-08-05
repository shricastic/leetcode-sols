class Solution {
private: 
    void splitNmap(string s, char delimiter, unordered_map<string, int>& map){
        vector<string> tokens;
        string token = "";
        
        for(char c : s){
            if(c == delimiter){if(!token.empty()) map[token]++, token.clear();}
            else {token+=c;}
        }
        
        if(!token.empty()) map[token]++;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string, int> map;
        
        splitNmap(s1, ' ', map);
        splitNmap(s2, ' ', map);
        
        for(auto it : map) if(it.second == 1) res.push_back(it.first);
        
        return res;
    }
};