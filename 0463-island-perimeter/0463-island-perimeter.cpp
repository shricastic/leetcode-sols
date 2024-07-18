class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0, rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 1) {
                    q.push({row, col});  
                }
            }
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            
            for(auto [rd, cd] : directions){
                int nr = rd + r, nc = cd + c;
                
                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] == 0){
                    perimeter++;
                }
            }
        }
        
        return perimeter;
    }
};