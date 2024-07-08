class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v;
        
        for(int i=1; i<=n ; i++){
            v.push_back(i);
        }
        
        int ci = 0;
        
        while(v.size()!=1){
            int n = v.size();
            ci = (ci+k-1)%n; 
            v.erase(v.begin()+ci);
        }
        
        return v[0];        
    }
};