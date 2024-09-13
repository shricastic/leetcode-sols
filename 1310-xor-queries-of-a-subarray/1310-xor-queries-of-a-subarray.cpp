class Solution {
private: 
    int getXOR(int x, int y){
        return (x | y) & (~x | ~y);
    }
    
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        
        for(auto query : queries){
            int start = query[0], end = query[1], cur = 0;
            for(int i=start ; i<=end ; i++) cur = getXOR(cur, arr[i]);
            res.push_back(cur);
        }
        
        return res;
    }
};