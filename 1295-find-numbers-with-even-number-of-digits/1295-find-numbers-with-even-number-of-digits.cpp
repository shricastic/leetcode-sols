class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res=0;
        
        for(int i:nums){
            string tmp = to_string(i);
            if(tmp.size()%2==0) res++;
        }
        
        return res;
    }
};