class Solution {
private:
    int n;
    vector<vector<string>> res;
    vector<string> grid;
    unordered_set<int> cols, d1, d2;
    
    void solve(int r){
        if(r == n){
            res.push_back(grid);
            return;
        }

        for(int c = 0 ; c<n ; c++){
            if(cols.count(c) || d1.count(r - c) || d2.count(r + c)) continue;
            
            grid[r][c] = 'Q';
            cols.insert(c);
            d1.insert(r-c); d2.insert(r+c);
            solve(r+1);

            grid[r][c] = '.';
            cols.erase(c);
            d1.erase(r-c); d2.erase(r+c);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        grid = vector<string>(n, string(n, '.'));
        solve(0);
        return res;
    }
};