class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        
        for(int i:nums){
            res.push_back(abs(i*i));
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};