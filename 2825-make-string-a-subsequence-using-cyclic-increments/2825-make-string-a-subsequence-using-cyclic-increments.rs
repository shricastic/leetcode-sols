impl Solution {
    pub fn can_make_subsequence(str1: String, str2: String) -> bool {
        let (s, t) : (Vec<char>, Vec<char>) = (str1.chars().collect(), str2.chars().collect());
        let (mut i, mut j) = (0, 0);
        
        while i<s.len() && j<t.len() {
            if s[i] == t[j] || (s[i] as u8 + 1 - b'a') % 26 + b'a' == t[j] as u8 { 
                j+=1;
            } 
            i+=1;
        }
        
        j==t.len()
    }
}