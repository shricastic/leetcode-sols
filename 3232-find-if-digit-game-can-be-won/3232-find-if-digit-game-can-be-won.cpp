class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum=0;
        
        for(int i : nums){
            i<10? sum+=i : sum-=i;
        }
        
        return sum==0 ? false : true;        
    }
};