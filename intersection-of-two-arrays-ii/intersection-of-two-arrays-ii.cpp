class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> map;
        
        for(int i:nums1){
            map[i]++;
        }
        
        for(int i : nums2){
            if(map.find(i) != map.end() && map[i] > 0){
                map[i]--;
                res.push_back(i);
            }
        }
        
        return res;
    }
};