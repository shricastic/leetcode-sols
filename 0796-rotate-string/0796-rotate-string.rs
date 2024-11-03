impl Solution {
    pub fn rotate_string(s: String, goal: String) -> bool {
        if s.len() != goal.len() {
            return false;
        }
        
        let twiceS = format!("{}{}", s, s);
        twiceS.contains(&goal)
    }
}