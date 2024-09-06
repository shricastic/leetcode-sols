class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;  
        
        for(int i = 0; i < k; i++){
            pq.push({nums[i], i});
        }
        
        res.push_back(pq.top().first);
        
        int fi = 0, li = k;
        
        while(li < nums.size()){
            while(!pq.empty() && pq.top().second <= fi) {
                pq.pop();
            }
            
            pq.push({nums[li], li});
            
            res.push_back(pq.top().first);
            
            fi++, li++;
        }
        
        return res;
    }
};