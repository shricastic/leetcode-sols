impl Solution {
    pub fn find_champion(n: i32, edges: Vec<Vec<i32>>) -> i32 {
        let mut in_deg = vec![0; n as usize];
        let mut res:i32 = -1; 
        
        for edge in &edges{
            in_deg[edge[1] as usize] += 1; 
        }
        
        for i in 0..n as usize{
            if in_deg[i] == 0 {
                if res==-1 {
                    res = i as i32;
                } else {
                    return -1;
                }
            } 
        }
        
        res
    }
}