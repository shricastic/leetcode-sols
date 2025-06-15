class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for(int &i: nums){
            if(set.count(i)>0) return i;
            set.insert(i);
        }

        return -1;
    }
};