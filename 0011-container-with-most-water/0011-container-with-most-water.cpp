class Solution {
public:
    int maxArea(vector<int>& height) {
        int ll = 0, rl = height.size()-1, maxWater = 0;
        
        while(ll<rl){
            int h = min(height[ll], height[rl]);
            int b = rl-ll; 
            maxWater =  max(maxWater, (h*b));
            
            if(height[ll]<height[rl]){
                ll++;
            } else{
                rl--;
            }
        }
        
        return maxWater;
    }
};