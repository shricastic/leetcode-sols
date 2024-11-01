class Solution {
public:
    string makeFancyString(string s) {
        string res = "";
        int n = s.size();
        
        for(int i=0 ; i<n ; i++){
            int m = res.size();
            if(m<2) {res+=s[i]; continue;}
            if((res[m-1] != res[m-2]) || (res[m-1] != s[i])) res += s[i];
        }
        
        return res;
    }
};