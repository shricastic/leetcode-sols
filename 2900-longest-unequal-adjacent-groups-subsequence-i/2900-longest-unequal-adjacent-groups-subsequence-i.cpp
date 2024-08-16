class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int pe = -1;
        vector<string> res1, res2;
        
        for(int i=0; i<groups.size() ; i++){
            if(groups[i] == 0 && pe == -1) pe = 0, res1.push_back(words[i]);
            if(pe != groups[i]) res1.push_back(words[i]), pe = groups[i]; 
        }
        
        pe = -1;
        
        for(int i=0; i<groups.size() ; i++){
            if(groups[i] == 1 && pe == -1) pe = 1, res2.push_back(words[i]);
            if(pe != groups[i]) res2.push_back(words[i]), pe = groups[i]; 
        }
        
        return res1.size()>res2.size()? res1 : res2;
    }
};