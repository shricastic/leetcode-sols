use std::collections::HashMap;

impl Solution {
    pub fn max_operations(nums: Vec<i32>, k: i32) -> i32 {
        let mut map = HashMap::new();
        let mut res = 0;
        
        for &i in &nums {
            if let Some(cnt) = map.get_mut(&(k-i)) {
                if *cnt>0 { 
                    res+=1; *cnt-=1; 
                    if *cnt == 0 { map.remove(&(k - i)); }
                }
            } else {
                *map.entry(i).or_insert(0) += 1;
            }
        }
        
        res
    }
}