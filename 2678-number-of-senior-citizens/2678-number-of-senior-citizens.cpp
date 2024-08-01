class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        
        for(string s : details){
            int i = s[11] - '0';
            int j = s[12] - '0';
            int age = (i*10) + j;
            
            
            if(age > 60) cnt++;
        }
        
        return cnt;
    }
};