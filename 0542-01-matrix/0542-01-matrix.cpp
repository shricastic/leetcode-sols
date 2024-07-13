class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> res(row, vector<int>(col, INT_MAX));
        queue<pair<int, int>> q;
        
        for(int r=0 ; r<row ; r++){
            for(int c=0 ; c<col ; c++){
                if(mat[r][c] == 0){
                    res[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            
            for(auto [rd, cd] : directions){
                    int nr = r+rd;
                    int nc = c+cd;
                    
                    if(nr<row && nr>=0 && nc<col && nc>=0){
                        if(res[nr][nc] > res[r][c] + 1){
                            res[nr][nc] = res[r][c]+1;
                            q.push({nr, nc});
                        }
                    }
                }
        }
        
        
        return res;       
    }
};