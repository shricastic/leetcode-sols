class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set;
        int res = -1;
        
        for(int i: nums) set.insert(i);
        
        for(int i: nums){
            if(i<0){
                if(set.count(abs(i))>0){
                    if (abs(i)>res) res=abs(i);
                }
            }
            
            if(i>0){
                if(set.count((0-i))>0){
                    if(res<i) res=i;
                }
            }
        }
        
        return res;
    }
};