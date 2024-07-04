class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        int res=0;   
        bool hasOdd = false;
        
        for(char c : s){
            map[c]++;
        }
        
        for(auto pair : map){
            if(pair.second %2 == 0){
                res += pair.second; 
            } else{
                res += pair.second - 1; 
                hasOdd = true;
            }
        }
        
        if(hasOdd){
            res++;
        }
        
        return res;
    }
};