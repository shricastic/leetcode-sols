class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int cnt = 0;
        
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '[') st.push('[');
            else {
                if (!st.empty()) st.pop(); 
                else cnt++;
            }
        }
        
        return (cnt+1)/2;
    }
};