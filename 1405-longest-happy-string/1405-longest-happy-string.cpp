class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        vector<pair<int, char>> counts = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        
        while (true) {
            sort(counts.begin(), counts.end(), greater<pair<int, char>>());
            bool added = false;
            
            for (auto& [count, ch] : counts) {
                if (count == 0) continue;
                
                int len = res.length();
                if (len >= 2 && res[len-1] == ch && res[len-2] == ch) {
                    continue;
                }
                
                res.push_back(ch);
                count--;
                added = true;
                break;
            }
            
            if (!added) break;
        }
        
        return res;
    }
};