class Solution {
private:
    int m, n;
    int dp[201][201];
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int>>& mt, int i, int j){
        if(i>=m || j>=n || i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxPath = 1;

        for(int d = 0 ; d<4 ; d++){
            auto [dx, dy] = dir[d];
            int x = i + dx, y = j + dy;

            if(x>=0 && x<m && y>=0 && y<n && mt[x][y] > mt[i][j]){
                maxPath = max(maxPath, 1 + dfs(mt, x, y));
            }
        }

        return dp[i][j] = maxPath;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->m = matrix.size(), this->n = matrix[0].size();
        int longestPath = 0;

        memset(dp, -1, sizeof(dp));

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                int curPathLen = dfs(matrix, i, j);
                longestPath = max(longestPath, curPathLen);
            }
        }

        return longestPath;
    }
};