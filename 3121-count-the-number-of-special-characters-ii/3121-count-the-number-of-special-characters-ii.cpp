class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> upper; 
        unordered_map<char, int> lower;
        int cnt = 0;
        
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            
            if(isupper(c)){
                if(upper.find(c) == upper.end()) upper[c] = i;
            }
            
            if(islower(c)){
                lower[c] = i;
            }
        }
        
        for(auto entry : lower){
            char c = entry.first;
           
            if(lower[c] < upper[toupper(c)]){
                cnt++;
            }
        }
        return cnt;
    }
};
