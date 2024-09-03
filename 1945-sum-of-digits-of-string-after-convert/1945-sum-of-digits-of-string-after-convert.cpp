class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;
        string str = "";
        
        for(char c : s) str += to_string(c-'`');
        
        while(k-->0){
            res = 0;
            for(char c : str) res+= c-'0';
            str = to_string(res);
        }
        
        return res;        
    }
};