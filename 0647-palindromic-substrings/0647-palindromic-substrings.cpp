class Solution {
private:
    string s;
    bool solve(int i, int j){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++, j--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        this-> s = s;
        int cnt = 0;
        for(int i=0; i<s.size() ; i++){
            for(int j=i; j<s.size() ; j++) if(solve(i, j)) cnt++;
        }
        
        return cnt;
    }
};