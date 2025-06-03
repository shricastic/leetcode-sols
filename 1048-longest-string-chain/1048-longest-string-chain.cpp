class Solution {
private:
    unordered_set<string> set;
    unordered_map<string, int> map;
    int solve(string s){
        if (map.find(s) != map.end()) return map[s];

        int maxLen = 1;
        for(int i=0 ; i<s.size() ; i++){
            string next = s.substr(0, i) + s.substr(i + 1);
            if(set.find(next) != set.end()) maxLen = max(maxLen, 1 + solve(next));
        } 

        return map[s] = maxLen;
    }
public:
    int longestStrChain(vector<string>& words) {
        for(string &w: words) set.insert(w);
        int maxLen = 0;

        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() > b.size();
        });

        for(int i=0 ; i<words.size() ; i++){
            maxLen = max(maxLen, solve(words[i]));
        }

        return maxLen;
    }
};