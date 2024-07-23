class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cnt;
        
        for(int num : nums) cnt[num]++;
        
        auto compare = [&] (int a, int b){
            if(cnt[a] == cnt[b]) return a>b;
            return cnt[a] < cnt[b];
        };
        
        sort(nums.begin(), nums.end(), compare);
        
        return nums;
    }
};