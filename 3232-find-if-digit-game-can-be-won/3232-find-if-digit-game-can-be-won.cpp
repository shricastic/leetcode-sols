class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sd = 0, dd = 0;
        
        for(int i : nums){
            if(i<10) sd+=i;
            else if(i>9 and i<100) dd+=i;
        }
        
        if(sd==dd) return false;
        return true;        
    }
};