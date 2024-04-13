class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> tmp;
        unordered_set<int> set;
        sort(nums.begin(), nums.end());
        
        for(int i:nums){
            if(set.contains(i)){
                continue;                
            } else{
                set.insert(i);
                tmp.push_back(i);
            }
        }
        
        return tmp.size()>=3 ? tmp[tmp.size()-3] : tmp[tmp.size()-1]; 
    }
};