impl Solution {
    pub fn max_equal_rows_after_flips(matrix: Vec<Vec<i32>>) -> i32 {
        let col = matrix[0].len();
        let mut max = 0;
        
        for cur_row in &matrix {
            let mut flipped_row = vec![0; col];
            let mut cur_max = 0;
            
            for i in 0..col { flipped_row[i] = 1-cur_row[i]; }
            
            for row in &matrix{
                if row == &flipped_row || row == cur_row{
                    cur_max += 1;
                }
            }

            max = max.max(cur_max);
        }
        
        max
    }
}