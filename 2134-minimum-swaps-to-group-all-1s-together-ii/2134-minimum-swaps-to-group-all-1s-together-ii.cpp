class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int totalOnes = count(nums.begin(), nums.end(), 1), 
        n = nums.size(), curOnes = 0, maxOnes = 0;
        
        for(int i=0 ; i<totalOnes ; i++) if(nums[i] == 1) curOnes++;
        
        maxOnes = curOnes;
        
        for(int i=totalOnes ; i<n*2 ; i++){
            if(nums[i%n] == 1) curOnes++;
            if(nums[(i-totalOnes) % n] == 1) curOnes--;   
            maxOnes = max(curOnes, maxOnes);
        }
        
        return totalOnes - maxOnes;
    }
};