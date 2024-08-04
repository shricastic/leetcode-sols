class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<long> maxHeap;
        long mod = 1000000007;
              
        for(int i=0 ; i<n ; i++){
            long sum = 0;
            for(int j=i ; j<n ; j++){
                sum += nums[j];
                maxHeap.push(sum);
                
                if(maxHeap.size()>right){
                    maxHeap.pop();
                }
            }
        }
        
        vector<long> v;
        
        while(!maxHeap.empty()){ v.push_back(maxHeap.top()); maxHeap.pop();}
    
        sort(v.begin(), v.end());
        
        long res = 0;

        for(int i=left-1 ; i<right ; i++) res = (res+v[i])%mod;
        
        return res;
    }
};