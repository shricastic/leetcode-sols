impl Solution {
    pub fn compressed_string(word: String) -> String {
        let mut res = String::new();
        
        if word.len()==0 {return res;}
        
        let wordChars: Vec<char> = word.chars().collect();
        let mut cnt: u32 = 1;
        
        for i in 1..wordChars.len() {
            if wordChars[i - 1] == wordChars[i] && cnt < 9 { cnt+=1;}
            else{
                res.push_str(&format!("{}{}", cnt, wordChars[i-1]));
                cnt = 1;
            }
        }
        
        res.push_str(&format!("{}{}", cnt, wordChars[wordChars.len()-1]));
        return res;
    }
}