class Solution {
public:
    bool checkString(string s) {
        bool flag = false;
        
        for(char c : s){
            if(c=='b' and !flag) flag = true;
            if(flag and c=='a') return false;             
        }
        
        return true;
    }
};