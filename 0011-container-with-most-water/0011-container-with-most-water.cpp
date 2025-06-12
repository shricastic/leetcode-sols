class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxVol = 0, li = 0, ri = height.size()-1;

        while(li<ri){
            int vol = (ri-li) * min(height[ri], height[li]);
            maxVol = max(vol, maxVol);

            if(height[li]>height[ri]) ri--;
            else li++;
        }

        return maxVol;
    }
};