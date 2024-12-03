impl Solution {
    pub fn add_spaces(s: String, spaces: Vec<i32>) -> String {
        let s: Vec<char> = s.chars().collect();
        let mut ans = String::new();
        let mut j: usize = 0;
        
        for i in 0..s.len(){
            if j<spaces.len() && i == spaces[j] as usize {
                ans.push(' ');
                j += 1;
            }
            ans.push(s[i]);
        }
        
        ans
    }
}