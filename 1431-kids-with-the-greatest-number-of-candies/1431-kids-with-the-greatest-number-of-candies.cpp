class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0; 

        for(int i:candies){
            if(i>max) max = i;
        }
        
        vector<bool> res;
        
        for(int i=0 ; i<candies.size() ; i++){
            int cur = candies[i]+extraCandies;
            if(cur>=max){
                res.push_back(true);
            } else{
                res.push_back(false);
            }
        }
        
        
        return res;    
        
    }
};