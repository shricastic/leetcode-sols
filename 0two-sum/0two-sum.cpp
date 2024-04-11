class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        res.resize(2, -1);
        
        for(int i=0 ; i<nums.size() ; i++){
            map[nums[i]] = i;
        }
        
        for(int i=0 ; i<nums.size() ; i++){
            int rem = target-nums[i];
            
            if(map.contains(rem) && map[rem]!=i){
                res[0] = i;
                res[1] = map[rem];
                break;
            }
        }
        
        return res;
    }
};