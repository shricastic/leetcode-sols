class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int maxArea = 0, n = h.size();
        vector<int> rl(n, 0), ll(n, 0);

        stack<int> st;

        for(int i=n-1 ; i>=0 ; i--){
            while(!st.empty() && h[st.top()] >= h[i]) st.pop();
            rl[i] = st.empty() ? n : st.top();

            st.push(i);
        } 

        st = stack<int>();

        for(int i=0 ; i<n ; i++){
            while(!st.empty() && h[st.top()] >= h[i]) st.pop();
            ll[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        for(int i=0 ; i<n ; i++){
            int width = rl[i] - ll[i] - 1;
            maxArea = max(maxArea, width*h[i]); 
        }

        return maxArea;
    }
};