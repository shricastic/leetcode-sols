class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0;
        
        for(char c : s){
            c=='(' ? open++ : open>0 ? open-- : close++;
        }
        
        return open+close;
    }
};