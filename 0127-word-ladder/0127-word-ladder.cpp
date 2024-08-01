class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> set(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({ beginWord, 1 });
       
        if(set.count(endWord) == 0) return 0;
        if(set.count(beginWord) > 0) set.erase(beginWord);
        
        while(!q.empty()){
            auto [word, level] = q.front(); q.pop();
            
            for(int i=0 ; i<word.size() ; i++){
                for(char c = 'a' ; c <= 'z' ; c++){
                    string nw = word;
                    nw[i] = c;
                    
                    if(nw == endWord) return level+1;
                    if(set.count(nw) > 0) set.erase(nw), q.push({nw, level+1});
                }
            } 
        }
        
        return 0;
    }
};