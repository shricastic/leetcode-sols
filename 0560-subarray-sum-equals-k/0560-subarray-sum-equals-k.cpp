class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;

        int sum = 0, cnt = 0;

        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
            if(map.find(sum-k) != map.end()) cnt+=map[sum-k];
            map[sum]++;
        } 

        return cnt;
    }
};