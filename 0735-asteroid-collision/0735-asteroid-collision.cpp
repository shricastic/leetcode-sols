class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for(int a : asteroids){
            bool destroyed = false;
            
            while(!st.empty() && st.top()>0 && a<0){
                int top = st.top();
                
                if(top+a == 0){
                    st.pop();
                    destroyed = true;
                    break;
                } else if(top+a > 0){
                    destroyed = true;
                    break;
                } else{
                    st.pop();
                }
            }
            
            if(!destroyed) st.push(a);
        }
        
        vector<int> res(st.size());
        for(int i=st.size()-1 ; i>=0 ; i--) res[i] = st.top(), st.pop();
          
        return res;
    }
};