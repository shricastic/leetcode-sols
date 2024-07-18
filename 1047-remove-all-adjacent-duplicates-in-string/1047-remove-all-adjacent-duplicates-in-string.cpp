class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        
        for(char c : s){
            if(!res.empty() && res[res.size()-1]==c){
                res.pop_back();
            } else{
                res.push_back(c);
            }
        }
        
        return res;
    }
};