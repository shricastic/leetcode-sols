class Solution {
public:
    vector<string> res;
    
    void helper(int op, int cp, int n, string cs){
        if(cs.size() == n*2){
            res.push_back(cs);
            return;
        }
        
        if(op<n) helper(op+1, cp, n, cs+'(');
        if(cp<op) helper(op, cp+1, n, cs+')');
    }
    
    vector<string> generateParenthesis(int n) {
        helper(0, 0, n, "");
        return res;
    }
};