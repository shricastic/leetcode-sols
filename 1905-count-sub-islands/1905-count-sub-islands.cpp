class Solution {
private:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    bool dfs(int r, int c, vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        if(r<0 || c<0 || r>=grid2.size() || c>=grid2[r].size() || grid2[r][c]==0){
            return true;
        }
        
        if(grid1[r][c] == 0) return false;
        
        grid2[r][c] = 0;
        
        bool subIsland = true;
        for(auto[rd, cd] : directions){
            int nr = r+rd, nc = c+cd;
            subIsland &= dfs(nr, nc, grid1, grid2);
        }
        
        return subIsland;
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0;
        
        for(int i=0 ; i<grid2.size() ; i++){
            for(int j = 0 ; j<grid2[0].size() ; j++){
                if(grid2[i][j] == 1){
                    if(dfs(i, j, grid1, grid2)) cnt++;
                }
            }
        }
        
        return cnt;
    }
};