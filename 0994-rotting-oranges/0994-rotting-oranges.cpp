class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> queue;
        int freshCnt = 0, mins = 0;
        
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j] == 2){
                    queue.push({i, j});
                } else if(grid[i][j] == 1){
                    freshCnt++;
                }
            }
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(freshCnt>0 && !queue.empty()){
            int currLevelSize = queue.size();
            
            for(int i=0 ; i<currLevelSize ; i++){
                auto [r, c] = queue.front();
                queue.pop();
                
                for(auto [rd, cd] : directions){
                    int nr = r + rd;
                    int nc = c + cd;
                    
                    if(nc>=0 && nc<cols && nr>=0 && nr<rows && grid[nr][nc]==1){
                        grid[nr][nc] = 2;
                        queue.push({nr, nc});
                        freshCnt--;
                    }
                }                
                
            }
            
            mins++;
        }
        
        return freshCnt==0 ? mins : -1;
    }
};