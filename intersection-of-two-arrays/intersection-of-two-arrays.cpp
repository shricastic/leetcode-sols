class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> set;
        
        for(int i:nums1){
            set.insert(i);
        }
        
        for(int i:nums2){
            if(set.count(i)){
                res.push_back(i);
                set.erase(i);
            }
        }
    
        return res;
    }
};