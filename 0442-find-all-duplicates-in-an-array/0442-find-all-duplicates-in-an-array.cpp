class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::set<int> set;
        vector<int> res;
        
        for(int num: nums){
            if(set.contains(num)){
                res.push_back(num);
            } else{
                set.insert(num);                
            }
        }
        
        
        return res;
    }
};