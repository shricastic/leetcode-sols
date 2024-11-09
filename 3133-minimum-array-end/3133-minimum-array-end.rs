impl Solution {
    pub fn min_end(mut n: i32, x: i32) -> i64 {
        let mut res: i64 = x as i64;  
        
        while n > 1 {
            n -= 1;
            res = (res + 1) | x as i64;  
        }
        
        res
    }
}