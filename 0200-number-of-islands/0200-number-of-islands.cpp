class Solution {
private:
    int m, n, res=0;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void dfs(vector<vector<char>> &g, int i, int j){
        if(g[i][j]!='1') return;
        g[i][j] = '2';

        for(auto [dr, dc]: dir){
            int r = i+dr, c = j+dc;
            if(r>=0 && r<m && c>=0 && c<n && g[r][c] == '1') dfs(g, r, c);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == '1') {
                    res++; dfs(grid, i, j);
                }    
            }
        }

        return res;
    }
};