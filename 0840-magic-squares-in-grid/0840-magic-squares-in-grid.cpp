class Solution {
private:
    bool isMagicSquare(int row, int col, vector<vector<int>>& grid) {
        unordered_set<int> set;
        int sum = 0;

        // Check if all numbers are between 1 and 9 and unique
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || set.count(num) > 0) return false;
                set.insert(num);
                if (i == row) sum += num; // Calculate sum of first row
            }
        }

        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; i++) {
            if (grid[row + i][col] + grid[row + i][col + 1] + grid[row + i][col + 2] != sum) return false;
            if (grid[row][col + i] + grid[row + 1][col + i] + grid[row + 2][col + i] != sum) return false;
        }
        if (grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2] != sum) return false;
        if (grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col] != sum) return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), cnt = 0;

        if (rows < 3 || cols < 3) return 0;

        for (int i = 0; i <= rows - 3; i++) {
            for (int j = 0; j <= cols - 3; j++) {
                if (isMagicSquare(i, j, grid)) cnt++;
            }
        }

        return cnt;
    }
};