class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        if(t.empty()) return {};
        vector<int> res(t.size(), 0);
        stack<int> st;

        for(int i=t.size()-1 ; i>=0 ; i--){
            while(!st.empty() && t[st.top()] <= t[i]) st.pop();
            if(!st.empty()) res[i] = st.top()-i;

            st.push(i);
        }
        
        return res;
    }
};