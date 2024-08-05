class Solution {
private: 
    vector<string> split(string s, char delimiter){
        vector<string> tokens;
        string token = "";
        
        for(char c : s){
            if(c == delimiter){if(!token.empty()) tokens.push_back(token), token.clear();}
            else {token+=c;}
        }
        
        if(!token.empty()) tokens.push_back(token);
        return tokens;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> res;
        unordered_map<string, int> map;
        
        for(string s : split(s1, ' ')) map[s]++;
        for(string s : split(s2, ' ')) map[s]++;
        
        for(auto it : map) if(it.second == 1) res.push_back(it.first);
        
        return res;
    }
};