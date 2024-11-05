impl Solution {
    pub fn min_changes(s: String) -> i32 {
        let mut ret = 0;
        let mut i = 0;
        let slice = s.as_bytes();
        while i < slice.len() - 1 {
            if &slice[i] != &slice[i+1] {
                ret = ret + 1;
            }
            i = i + 2;
        }
        return ret;
    }
}
