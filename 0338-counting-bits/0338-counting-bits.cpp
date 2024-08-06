class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        
        vector<int> v(n+1, 0);
        v[0] = 0, v[1] = 1;
        
        for(int i=2 ; i<=n ; i++)
            v[i] = v[i/2] + i%2;
        
        return v;
    }
};