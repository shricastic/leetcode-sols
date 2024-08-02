class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = count(nums.begin(), nums.end(), 1);
        vector<int> tmp(nums);
        tmp.insert(tmp.end(), nums.begin(), nums.end());
        int curOnes = 0;
        
        for(int i=0 ; i<totalOnes ; i++){
            if(tmp[i] == 1) curOnes++;
        }
        
        int maxOnes = curOnes;
        
        for(int i=totalOnes ; i<tmp.size() ; i++){
            if(tmp[i] == 1) curOnes++;
            if(tmp[i-totalOnes] == 1) curOnes--;
            
            maxOnes = max(curOnes, maxOnes);
        }
        
        return totalOnes-maxOnes;
    }
};