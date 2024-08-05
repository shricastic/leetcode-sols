class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> map1, map2;
        int res = 0;
        
        for(string s : words1) map1[s]++;
        for(string s : words2) map2[s]++;
        
        for(string s : words1){
            if(map1[s]==1 && map2[s]==1) res++;
        }
        
        return res;
    }
};