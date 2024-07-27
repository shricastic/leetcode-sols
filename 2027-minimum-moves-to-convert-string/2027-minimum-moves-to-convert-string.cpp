class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size(), cnt = 0;
        
        for (int i = 0; i < n; ) {
            if (s[i] == 'X')  cnt++, i += 3;  
            else i++;
        }
        
        return cnt;
    }
};
