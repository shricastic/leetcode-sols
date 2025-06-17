class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for(int i: nums){
            if(map.count(i)>0) map[i]++;
            else map[i] = 1;
        }

        priority_queue<pair<int, int>> pq;

        for(auto &kp : map){
            pair<int, int> p;
            p.first = kp.second;
            p.second = kp.first;

            pq.push(p);
        }

        vector<int> res;
        while(k--){
            pair<int, int> p = pq.top();
            pq.pop();
            res.push_back(p.second);
        }

        return res;
    }
};