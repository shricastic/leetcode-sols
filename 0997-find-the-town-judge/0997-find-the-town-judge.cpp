class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        
        vector<int> trustedby(n+1, 0);
        vector<int> trusts(n+1, 0);
        
        for(auto v : trust){
            trusts[v[0]]++;
            trustedby[v[1]]++;
        }
        
        for(int v=0 ; v<=n ; v++){
            if(trusts[v] == 0 && trustedby[v] == n-1) return v;
        }
        
        return -1;
    }
};