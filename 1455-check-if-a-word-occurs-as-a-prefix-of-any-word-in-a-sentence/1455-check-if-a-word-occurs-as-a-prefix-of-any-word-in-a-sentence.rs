impl Solution {
    pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
        let list: Vec<&str> = sentence.split_whitespace().collect();

        for i in 0..list.len() {
            if list[i].starts_with(&search_word) {
                return (i + 1) as i32;
            }
        }
        
        -1
    }
}