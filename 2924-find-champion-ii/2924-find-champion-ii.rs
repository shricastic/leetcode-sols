impl Solution {
    pub fn find_champion(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let (mut in_deg, mut res) = (vec![0; n as usize], -1);
        
        for edge in &edges{ in_deg[edge[1] as usize] += 1; }
        
        for i in 0..n as usize{
            if in_deg[i] == 0 {
               res = if res == -1 { i as i32 } else { return -1 };
            } 
        }
        
        res
    }
}