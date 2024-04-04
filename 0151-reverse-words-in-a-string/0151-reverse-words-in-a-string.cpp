#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    void removeSpaces(string& s) {
        while (!s.empty() && isspace(s.front())) {
            s.erase(s.begin()); // Remove leading spaces
        }
        
        while (!s.empty() && isspace(s.back())) {
            s.pop_back(); // Remove trailing spaces
        }
        
        size_t pos;
        while ((pos = s.find("  ")) != string::npos) {
            s.erase(pos, 1); // Remove consecutive spaces
        }
    }
    
    vector<string> toCharArray(string s, char delimiter) {
        vector<string> wordsArray;
        stringstream ss(s);
        string word;
        
        while (getline(ss, word, delimiter)) {
            wordsArray.push_back(word);
        }
        
        return wordsArray;
    }    

    string reverseWords(string s) {
        removeSpaces(s);
        vector<string> v = toCharArray(s, ' ');
        
        string res;
        for (string word : v) {
            if(res.size()==0){
                res+=word;
            } else{
                res = word + " " + res;
            }
        }    
        return res;
    }
};
