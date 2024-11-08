impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let s1: Vec<char> = word1.chars().collect();
        let s2: Vec<char> = word2.chars().collect();
        
        let n = word1.len().max(word2.len());
        let mut i = 0;
        
        let mut res = String::new();
        
        while i<n {
            if(i<word1.len()) {res.push(s1[i]);}
            if(i<word2.len()) {res.push(s2[i]);}
            i += 1;
        }
        
        res
    }
}