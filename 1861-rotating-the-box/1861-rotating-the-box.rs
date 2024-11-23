impl Solution {
    pub fn rotate_the_box(grid: Vec<Vec<char>>) -> Vec<Vec<char>> {
        let mut grid = grid; 
        let m = grid.len();
        let n = grid[0].len();
        let mut res = vec![vec!['.'; m]; n];
        
        for row in grid.iter_mut() {
            let mut stone_pos = n - 1; 
            let mut scan_pos = n - 1;  
            
            while scan_pos < n {  
                if row[scan_pos] == '*' {
                    stone_pos = scan_pos;
                } else if row[scan_pos] == '#' {
                    if stone_pos > scan_pos && row[stone_pos] == '.' {
                        row[scan_pos] = '.';
                        row[stone_pos] = '#';
                    }
                }
                
                while stone_pos > 0 && row[stone_pos] != '.' {
                    stone_pos -= 1;
                }
                
                if scan_pos > 0 {
                    scan_pos -= 1;
                } else {
                    break;
                }
            }
        }
        
        for i in 0..m {
            for j in 0..n {
                res[j][m - 1 - i] = grid[i][j];  
            }
        }
        
        res
    }
}