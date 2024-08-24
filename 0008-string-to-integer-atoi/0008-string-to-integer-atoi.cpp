class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        istringstream strm(s);
        
        strm>>res;
        
        return res;       
    }
};