use std::collections::HashSet;

impl Solution {
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        let mut set = HashSet::new();
        
        for &i in &arr {
            set.insert(i);
        }
        
        for &i in &arr {
            if i != 0 && set.contains(&(i * 2)) { 
                return true;
            }
        }
        
        if arr.iter().filter(|&&x| x == 0).count() > 1 {
            return true;
        }
        
        false
    }
}
