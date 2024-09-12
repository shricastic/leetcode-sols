class Solution {
private:
    bool isConsistent(unordered_set<char> &set, string s){
        for(char c : s) if(set.count(c) == 0) return false;
        return true;
    }
    
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> set;
        for(char c : allowed) set.insert(c);
        
        int cnt = 0;
        for(string s : words) if(isConsistent(set, s)) cnt++;
        
        return cnt;
    }
};