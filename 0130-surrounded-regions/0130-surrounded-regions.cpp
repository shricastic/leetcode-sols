class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = board[0].size();
        queue<pair<int, int>> q;
        
        for(int row = 0; row<rows ; row++){
            for(int col = 0 ; col<cols ; col++){
                if((row == 0 || row==rows-1 || col==0 || col==cols-1) && board[row][col]=='O'){
                    q.push({row, col});
                }
            }
        }
        
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            
            if(r<rows and r>=0 and c<cols and c>=0 and board[r][c]=='O'){
                board[r][c] = 'T';
                if(r-1 >= 0) q.push({r-1, c});
                if(r+1 < rows) q.push({r+1, c});
                if(c-1 >= 0) q.push({r, c-1});
                if(c+1 < cols) q.push({r, c+1});
            }
        }
        
        for(int row = 0; row<rows ; row++){
            for(int col = 0 ; col<cols ; col++){
                if(board[row][col]=='O') board[row][col] = 'X';
                else if(board[row][col] == 'T') board[row][col] = 'O';
            }
        }       
    }
};