class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int li = 0, maxLen = 0;

        for(int ri = 0; ri<s.size() ; ri++){
            while(set.count(s[ri])>0){
                set.erase(s[li]);
                li++;
            }

            set.insert(s[ri]);
            maxLen = max(maxLen, ri-li+1);
        }
        
        return maxLen;
    }
};