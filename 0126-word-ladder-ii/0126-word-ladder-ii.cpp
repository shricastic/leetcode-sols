class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        unordered_map<string, vector<string>> parents;
        unordered_set<string> current, next;
        current.insert(beginWord);
        
        bool found = false;
        while (!current.empty() && !found) {
            for (const string& word : current) {
                dict.erase(word);
            }
            
            for (const string& word : current) {
                string temp = word;
                for (char& c : temp) {
                    char orig = c;
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        c = ch;
                        if (dict.count(temp)) {
                            next.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                    }
                    c = orig;
                }
            }
            current.swap(next);
            next.clear();
        }
        
        if (!found) return {};
        
        vector<vector<string>> res;
        vector<string> path = {endWord};
        dfs(res, path, parents, beginWord, endWord);
        
        return res;
    }
    
private:
    void dfs(vector<vector<string>>& res, vector<string>& path, 
             unordered_map<string, vector<string>>& parents, 
             const string& beginWord, const string& word) {
        if (word == beginWord) {
            res.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }
        for (const string& parent : parents[word]) {
            path.push_back(parent);
            dfs(res, path, parents, beginWord, parent);
            path.pop_back();
        }
    }
};