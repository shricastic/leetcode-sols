class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        map.insert({0, -1});
        int sum = 0, maxl = 0;
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i] == 0? 1 : -1;
            if(map.count(sum)) maxl = max(maxl, i-map[sum]);
            else map.insert({sum, i});
        }
        
        return maxl;
    }
};