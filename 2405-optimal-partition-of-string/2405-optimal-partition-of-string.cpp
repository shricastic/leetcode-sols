class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> set;
        int res = 1;
        
        for(char c : s){
            if(set.count(c)>0){
                res++;
                set.clear();
            }  
            set.insert(c);
        }
        
        return res;
    }
};