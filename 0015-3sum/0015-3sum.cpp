class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(int i=0 ; i<nums.size() ; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int li = i+1, ri = nums.size()-1;
            
            while(li<ri){
                int sum = nums[i] + nums[li] + nums[ri];
                
                if(sum==0){
                    res.push_back({nums[i], nums[li], nums[ri]});
                    
                    while(li<ri && nums[li] == nums[li+1]) li++;
                    while(li<ri && nums[ri] == nums[ri-1]) ri--;
                    
                    li++; 
                    ri--;
                } else if(sum < 0){
                    li++;
                } else{
                    ri--;
                }
            }
        }
        
        return res;        
    }
};