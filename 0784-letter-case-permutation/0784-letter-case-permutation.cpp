class Solution {
private:
    vector<string> v;
    
    void permutation(string& s, string res, int i){
        if(i==res.size()) {
            v.push_back(res);
            return;
        }    
        
        permutation(s, res, i+1);
        
        if(isalpha(res[i])){
            res[i]^=32;
            permutation(s, res, i+1);
        }
    }
    
public:
    vector<string> letterCasePermutation(string s) {
        permutation(s, s, 0);
        return v;
    }
};