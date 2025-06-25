class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), mins = 0, fresh=0;
        if(r == 0) return -1;

        queue<pair<int, int>> q;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while(!q.empty()){
            int lsize = q.size();
            bool rottenThisMin = false;

            while(lsize--){
                auto [cr, cc] = q.front(); q.pop();

                for(auto [dr, dc]: dir){
                    int nr = cr+dr, nc = cc+dc;

                    if(nr>=0 && nr<r && nc>=0 && nc<c && grid[nr][nc]==1 && grid[cr][cc]==2){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                        rottenThisMin = true;
                    }
                }
            }

            if(rottenThisMin) mins++;
        }
        
        for(int i=0; i<r ; i++){
            for(int j=0; j<c ; j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return fresh==0? mins : -1;
    }
};