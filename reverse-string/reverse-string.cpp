class Solution {
public:
    void reverse(vector<char>& s, int fi, int li){
        if(fi>=li) return;
        char c = s[fi];
        s[fi] = s[li];
        s[li] = c;
        
        reverse(s, ++fi, --li);
    }
    
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size()-1);
    }
};