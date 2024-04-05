class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> set;
        
        for(int i : nums){
            if(set.find(i) != set.end()){
                set.erase(i);
            } else{
                set.insert(i);    
            }
        }
        
        return *set.begin();
    }
};
