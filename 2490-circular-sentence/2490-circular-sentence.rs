impl Solution {
    pub fn is_circular_sentence(sentence: String) -> bool {
        let words: Vec<&str> = sentence.split_whitespace().collect();
        
        for i in 0..words.len() {
            let current_word = words[i];
            let next_word = words[(i + 1) % words.len()]; 
            
            if current_word.chars().last() != next_word.chars().next() {
                return false;
            }
        }
        
        true
    }
}
