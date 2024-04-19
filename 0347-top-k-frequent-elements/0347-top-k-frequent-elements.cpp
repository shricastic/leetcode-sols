class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>  map;
        
        for(auto i : nums) map[i]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(auto entry : map){
            pq.push({entry.second, entry.first});
        }
        
        vector<int> ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();                        
        }
        
        return ans;  
    }
};