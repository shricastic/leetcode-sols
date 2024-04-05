class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sres = "";
        string tres = "";
        
        for(char c : s){
            if(!sres.empty()&&(c=='#')){
                sres.pop_back();                
            } else if(c!='#'){
                sres+=c;
            }
        }
        
        for(char c : t){
            if(!tres.empty()&&(c=='#')){
                tres.pop_back();                
            } else if(c!='#'){
                tres+=c;
            }
        }
        
        if(sres!=tres) return false;
        
        return true;        
    }
};