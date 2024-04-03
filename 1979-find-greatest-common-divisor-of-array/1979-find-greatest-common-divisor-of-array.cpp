class Solution {
    int gcd(int max, int min){
        while(min!=0){
            int remainder = max%min;
            max = min;
            min = remainder;
        }   
        return max;
    }
    
public:
    int findGCD(vector<int>& nums) {
        int min = nums[0];
        int max = nums[0];
        
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]<min) min = nums[i];
            if(nums[i]>max) max = nums[i];
        }
        
        return gcd(min, max);
    }
};