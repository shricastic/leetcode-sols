class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> exists(nums.size(), false);
        
        for(int num : nums){
            if(exists[num]){
                return num;
            } else{
                exists[num] = true;
            }
        }
        
        return -1;
    }
};