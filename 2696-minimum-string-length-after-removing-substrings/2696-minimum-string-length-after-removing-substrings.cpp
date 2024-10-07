class Solution {
public:
    int minLength(string s) {
        string stk = "";
        
        for(int i=0 ; i<s.size() ; i++){
            if(stk.empty()) stk+=s[i];
            else{
                if((stk.back()=='A' && s[i]=='B') || (stk.back()=='C' && s[i]=='D')){
                    stk.pop_back();
                } else{
                    stk += s[i];
                }
            }
        }
                   
        return stk.size();
    }
};