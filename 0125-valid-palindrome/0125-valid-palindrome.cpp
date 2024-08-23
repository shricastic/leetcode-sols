class Solution {
private:
    void convert(string &s) {
        int writeIndex = 0;
        for (char c : s) {
            if (isalnum(c)) {
                s[writeIndex++] = tolower(c);
            }
        }
        s.resize(writeIndex);
    }
    
    bool checkPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
public:
    bool isPalindrome(string s) {
        convert(s);
        return checkPalindrome(s);
    }
};