class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxl = 0;
        
        for(char c : s){
            c=='(' ? left++ : right++;           
            if(left==right) maxl = max(maxl, left*2);
            if(left<right) left = 0, right = 0; 
        }
        
        left = 0, right = 0;
        for(int i=s.length()-1 ; i>=0 ; i--){
            char c = s[i];
            c=='(' ? left++ : right++;           
            if(left==right) maxl = max(maxl, left*2);
            if(left>right) left = 0, right = 0; 
        }
        
        return maxl;
    }
};