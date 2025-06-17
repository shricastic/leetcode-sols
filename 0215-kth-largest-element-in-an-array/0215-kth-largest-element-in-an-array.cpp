class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()<k) return -1; 
        priority_queue<int> q;
        
        for(int i: nums) q.push(i);

        while(k-1){
            q.pop(); 
            k--;
        }

        return q.top();
    }
};