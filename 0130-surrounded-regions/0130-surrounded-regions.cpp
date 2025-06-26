class Solution {
private:
    int m, n;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
    void dfs(vector<vector<char>> &b, int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n || b[i][j] != 'O') return;

        b[i][j] = 'T';
        for(auto [r, c]: dir){
            dfs(b, i + r, j + c);
        }
    }

public:
    void solve(vector<vector<char>>& b) {
        m = b.size();
        n = b[0].size();

        for(int j = 0; j < n; j++) {
            if(b[0][j] == 'O') dfs(b, 0, j);
            if(b[m - 1][j] == 'O') dfs(b, m - 1, j);
        }

        for(int i = 0; i < m; i++) {
            if(b[i][0] == 'O') dfs(b, i, 0);
            if(b[i][n - 1] == 'O') dfs(b, i, n - 1);
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(b[i][j] == 'O') b[i][j] = 'X';
                else if(b[i][j] == 'T') b[i][j] = 'O';
            }
        }
    }
};
