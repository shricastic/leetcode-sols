class Solution {
public:
    int secondHighest(string s) {
        set<int> set;
        
        for(char c : s){
            if(isdigit(c)){
                set.insert(c-'0');         
            }
        }
        
        if(set.size()<2) return -1;
        
        auto it = set.rbegin();
        it++;
        
        return *it;
    }
};