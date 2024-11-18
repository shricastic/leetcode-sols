impl Solution {
    pub fn decrypt(code: Vec<i32>, k: i32) -> Vec<i32> {
        let n = code.len();
        let mut res = vec![0; n];
        
        if k > 0 {
            for i in 0..n {
                let mut sum = 0;
                for j in 1..=k as usize {
                    sum += code[(i + j) % n];
                }
                res[i] = sum;
            }
        } else if k < 0 {
            for i in 0..n {
                let mut sum = 0;
                for j in 1..=(-k) as usize {
                    sum += code[(i - j + n) % n];
                }
                res[i] = sum;
            }
        }
        
        res
    }
}