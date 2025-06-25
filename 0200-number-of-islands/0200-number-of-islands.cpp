class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1') {
                    res++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '2'; 

                    while(!q.empty()){
                        auto [r, c] = q.front(); q.pop();

                        for(auto [dr, dc] : dirs){
                            int nr = r + dr, nc = c + dc;
                            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1'){
                                q.push({nr, nc});
                                grid[nr][nc] = '2';
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};
