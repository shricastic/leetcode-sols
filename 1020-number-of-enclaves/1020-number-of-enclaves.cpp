class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), cnt = 0;
        queue<pair<int, int>> q;
        
        for(int r = 0 ; r<row ; r++){
            for(int c = 0 ; c<col ; c++){
                if(grid[r][c] == 1) cnt++;
                if((c==0 || c==col-1 || r==0 || r==row-1) and grid[r][c] == 1){
                    q.push({r,c});
                    grid[r][c] = 0;
                    cnt--;
                }
            }
        }
  
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            
            for(auto [rd, cd] : directions){
                int nr = rd+r, nc = cd+c ; 
                
                if(nr>=0 and nr<row and nc>=0 and nc<col and grid[nr][nc]==1){
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                    cnt--;
                }
            }
            
        }
        
        return cnt;
    }
};