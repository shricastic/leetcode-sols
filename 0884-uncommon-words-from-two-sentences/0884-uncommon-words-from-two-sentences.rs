use std::collections::HashMap;

impl Solution {
    pub fn uncommon_from_sentences(s1: String, s2: String) -> Vec<String> {
        let mut map1 = HashMap::new();
        let mut map2 = HashMap::new();
        
        for word in s1.split_whitespace() {
            map1.entry(word.to_string()).and_modify(|count| *count += 1).or_insert(1);
        }
        
        for word in s2.split_whitespace() {
            map2.entry(word.to_string()).and_modify(|count| *count += 1).or_insert(1);
        }
        
        let mut res = Vec::new();
        
        for (word, cnt) in map1.iter() {
            if *cnt == 1 && !map2.contains_key(word){
                res.push(word.clone());
            }
        }
        
        for (word, cnt) in map2.iter() {
            if *cnt == 1 && !map1.contains_key(word){
                res.push(word.clone());
            }
        }
        
        res
    }
}

       