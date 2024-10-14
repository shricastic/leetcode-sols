#define ll long long

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> pq;
        
        for(int num : nums) pq.push(num);
        
        ll res = 0; 
        while(k>0){
            int tmp = pq.top();
            pq.pop();
            res+=tmp;
            
            pq.push(ceil(tmp/3.0));
            k--;
        }
        
        return res;       
    }
};