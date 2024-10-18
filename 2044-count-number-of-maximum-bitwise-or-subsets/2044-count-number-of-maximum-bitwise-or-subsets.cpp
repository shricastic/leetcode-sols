class Solution {
private:
    void backtrack(vector<int>& nums, int idx, int curOr, int max, int &cnt){
        if(curOr == max) cnt++;
        
        for(int i=idx ; i<nums.size() ; i++){
            backtrack(nums, i+1, curOr|nums[i], max, cnt);
        }
    }
    
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0, cnt=0;
        
        for(int num : nums) max |= num;
        
        backtrack(nums, 0, 0, max, cnt);
        
        return cnt;
    }
};