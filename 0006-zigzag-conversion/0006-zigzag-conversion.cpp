class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> grid(numRows);
        int li=numRows-1, i=0, si=0;
        bool down = true;
        
        while(si<s.size()){
            grid[i].push_back(s[si++]);
            
            if(down) i++; else i--;
            
            if(i==0 || i==li) down = !down;
        }
        
        string res;
        for(string &str : grid) res += str;
        
        return res;
    }
};