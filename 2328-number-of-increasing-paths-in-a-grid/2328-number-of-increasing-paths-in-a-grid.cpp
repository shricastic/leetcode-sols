class Solution {
private:
    int m, n;
    int dp[1001][1001];
    int MOD = 1e9 + 7;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int>>& gd, int i, int j){
        if(dp[i][j] != -1) return dp[i][j];

        int paths = 0;

        for(int d = 0 ; d<4 ; d++){
            auto[dirx, diry] = dir[d];
            int x = i+dirx, y = j+diry;

            if(x>=0 && y>=0 && x<m && y<n && gd[x][y] > gd[i][j]){
                paths = (paths + dfs(gd, x, y) + 1) % MOD;
            }
        }

        return dp[i][j] = paths;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        this->m = grid.size(), this->n = grid[0].size();
        int maxPaths = 0;
        maxPaths += m*n;

        memset(dp, -1, sizeof(dp));

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                maxPaths = (dfs(grid, i, j) + maxPaths) %MOD;
            }
        }

        return maxPaths;
    }
};