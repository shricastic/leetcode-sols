class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = count(nums.begin(), nums.end(), 1), curOnes = 0, maxOnes = 0;
        vector<int> tmp(nums);
        tmp.insert(tmp.end(), nums.begin(), nums.end());
        
        for(int i=0 ; i<totalOnes ; i++) if(tmp[i] == 1) curOnes++;
        
        maxOnes = curOnes;
        
        for(int i=totalOnes ; i<tmp.size() ; i++){
            if(tmp[i] == 1) curOnes++;
            if(tmp[i-totalOnes] == 1) curOnes--;   
            maxOnes = max(curOnes, maxOnes);
        }
        
        return totalOnes - maxOnes;
    }
};