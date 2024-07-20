class Solution {
public:
    int partitionString(string s) {
        vector<bool> charmap(26, false);
        int res = 1;
        
        for(char c : s){
            if(charmap[c-'a']==true){
                res++;
                fill(charmap.begin(), charmap.end(), false);
            }  
            charmap[c-'a'] = true;
        }
        
        return res;
    }
};