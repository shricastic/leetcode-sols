class Solution {
private:
    bool isConsistent(unordered_set<string> &set, string s){
        for(char c : s) if(set.count(to_string(c)) == 0) return false;
        return true;
    }
    
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<string> set;
        for(char c : allowed) set.insert(to_string(c));
        
        int cnt = 0;
        for(string s : words) if(isConsistent(set, s)) cnt++;
        
        return cnt;
    }
};