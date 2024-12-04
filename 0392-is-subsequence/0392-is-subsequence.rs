impl Solution {
    pub fn is_subsequence(s: String, t: String) -> bool {
        let (mut sarr, mut tarr): (Vec<char>, Vec<char>) = (s.chars().collect(), t.chars().collect());
        let (mut i, mut j) = (0, 0);
        
        while i < sarr.len() && j < tarr.len() {
            if sarr[i] == tarr[j] {
                i += 1;
            }
            j += 1;
        }
        
        i == sarr.len()
    }
}
