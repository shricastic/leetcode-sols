class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        while(stones.size()>1){
            sort(stones.begin(), stones.end());
            int n = stones.size();
            
            int smashRes = stones[n-1] - stones[n-2];
            stones.pop_back();
            stones.pop_back();
            
            if(smashRes>0){
                stones.push_back(smashRes);
            }    
        }
        
        if(stones.empty()){
            return 0;
        } 
        
        return stones[0];
    }
};