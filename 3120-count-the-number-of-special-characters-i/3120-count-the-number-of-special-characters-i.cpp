class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool chars[128] = {false};
        int cnt = 0;
        
        for(char c : word){
            int idx = static_cast<int>(c);
            chars[idx] = true;
        };
        
        for(int i=65 ; i<91 ; i++){
            if(chars[i] && chars[i+32]){
                cnt++;
            }
        }
        
        return cnt;
    }
};