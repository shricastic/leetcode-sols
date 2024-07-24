class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), idx = 0;
        if(n<2) return n;
        
        for(int i=0; i<chars.size() ; i++){
            int j = i;
            
            while(j<n and chars[i] == chars[j]) j++;
            
            chars[idx] = chars[i];
            idx++;
            
            if(j-i > 1){
                string str = to_string((j-i));
                for(char c : str) chars[idx++] = c;
            }
            
            i = j-1;
        }
        
        chars.resize(idx);
        return idx;
    }
};