class Solution {
public:
    void reverse(string &word, int li){
        int fi=0;
        
        while(fi<li){
            char tmp = word[fi];
            word[fi] = word[li];
            word[li] = tmp;
            li--;
            fi++;
        }
    }
    
public:
    string reversePrefix(string word, char ch) {
        for(int i=0; i<word.size() ; i++){
            if(word[i]==ch){
                reverse(word, i);
                break;
            }
        }
        
        return word;
    }
};