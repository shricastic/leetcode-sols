class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size(), fi = 0, ei = 0, cnt = t.size(), minLen = INT_MAX;
        string minStr = "";

        if (n < m) return "";  

        unordered_map<char, int> map;
        for (char &c : t) map[c]++;  

        while (ei < n) {
            char c = s[ei];

            if (map.count(c) > 0) {
                map[c]--;
                if (map[c] >= 0) cnt--;  
            }

            while (cnt == 0) {
                if (ei - fi + 1 < minLen) {
                    minLen = ei - fi + 1;
                    minStr = s.substr(fi, minLen);  
                }

                char lchar = s[fi];
                if (map.count(lchar) > 0) {
                    map[lchar]++;
                    if (map[lchar] > 0) cnt++;  
                }
                fi++;  
            }
            ei++;  
        }

        return minStr;  
    }
};
