class Solution {
private:
    vector<string> res;
    string digits;
    vector<string> map;
    
    void combinations(int index, string current) {
        if (index == digits.length()) {
            res.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        for (char c : map[digit]) {
            combinations(index + 1, current + c);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        this->digits = digits;
        map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        combinations(0, "");
        
        return res;
    }
};