class Solution {
private:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    
    void lexiString(int n, int index, int len, int& cnt) {
        if (len == n) {
            cnt++;
            return;
        }
        
        for (int i = index; i < vowels.size(); i++) {
            lexiString(n, i, len + 1, cnt);     
        }
    }

public:
    int countVowelStrings(int n) {
        int cnt = 0;
        lexiString(n, 0, 0, cnt);
        return cnt;
    }
};