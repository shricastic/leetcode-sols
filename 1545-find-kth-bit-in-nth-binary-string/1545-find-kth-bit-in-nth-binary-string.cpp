class Solution {
private:
    string invert(string s){
        for(int i=0 ; i<s.size() ; i++) s[i]=='0'? s[i]='1' : s[i]='0';
        reverse(s.begin(), s.end());
        return s;
    }
    
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=2 ; i<=n ; i++) s = s + "1" + invert(s);
        return s[k-1];
    }
};