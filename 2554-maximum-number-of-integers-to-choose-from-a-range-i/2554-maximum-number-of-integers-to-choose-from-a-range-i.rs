use std::collections::HashSet;

impl Solution {
    pub fn max_count(banned: Vec<i32>, n: i32, max_sum: i32) -> i32 {
        let mut set = HashSet::new();
        let (mut sum, mut cnt) = (0, 0);
        
        for num in &banned{ set.insert(num); }
        
        for i in 1..=n{
            if (sum + i as i32) > max_sum { break; }
            if set.contains(&(i as i32)) { continue; } 
            sum+=i as i32;
            cnt+=1;
        }
        
        cnt
    }
}