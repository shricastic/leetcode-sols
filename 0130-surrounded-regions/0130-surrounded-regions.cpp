class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size(), col = board[0].size();
        queue<pair<int, int>> q;

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if ((r == 0 || r == row - 1 || c == 0 || c == col - 1) && board[r][c] == 'O') {
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            if (r >= 0 && r < row && c >= 0 && c < col && board[r][c] == 'O') {
                board[r][c] = 'B'; 
                if (r - 1 >= 0) q.push({r - 1, c});
                if (r + 1 < row) q.push({r + 1, c});
                if (c - 1 >= 0) q.push({r, c - 1});
                if (c + 1 < col) q.push({r, c + 1});
            }
        }

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == 'B') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
