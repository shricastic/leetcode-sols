class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1; 
        vector<int> cnt(n + 1, 0);

        for (const auto& edge : edges) {
            cnt[edge[0]]++;
            cnt[edge[1]]++;
        }
        
        
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};

