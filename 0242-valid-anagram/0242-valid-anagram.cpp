class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        vector<int> dict(26, 0);
        
        for(char c : s) dict[c-'a']++;
        for(char c : t) dict[c-'a']--;
        
        for(int i : dict) if(i!=0) return false;
        
        
        return true;
    }
};