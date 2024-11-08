use std::collections::HashMap;

#[derive(Default)]
struct TrieNode{
    children: HashMap<char, TrieNode>,
    end_word: bool
}

struct Trie{
    root: TrieNode,
}

impl Trie {
    fn new() -> Self {
        Trie { root : TrieNode::default(), }
    }
    
    fn insert(&mut self, word: &String){
        let mut node = &mut self.root;
        
        for c in word.chars() {
            if !node.children.contains_key(&c) {
                node.children.insert(c, TrieNode::default());
            }   
            node = node.children.get_mut(&c).unwrap();
        }
        node.end_word=true
    }
    
    fn starts_with(&self, prefix: &String) -> Vec<String> {
        let mut node = &self.root;
        
        for c in prefix.chars() {
            if !node.children.contains_key(&c) {
                return vec![];
            }
            node = node.children.get(&c).unwrap();
        }
        
        let mut result = vec![];
        let mut cur_word = String::from(prefix);
        self.dfs(node, &mut cur_word, &mut result);
        
        result
    }
    
    fn dfs(&self, node: &TrieNode, cur_word:&mut String, result: &mut Vec<String>){
        if node.end_word{
            result.push(cur_word.clone());
        }
        
        for (&c, child) in &node.children {
            cur_word.push(c);
            self.dfs(child, cur_word, result);
            cur_word.pop();
        }
    }
}


impl Solution {
    pub fn suggested_products(products: Vec<String>, search_word: String) -> Vec<Vec<String>> {
        let mut t = Trie::new();
        let mut res = Vec::new();
        
        for p in products {
            t.insert(&p);
        }
        
        let mut curprefix = String::new();
        
        for s in search_word.chars() {
            curprefix.push(s);
            let mut sugg = t.starts_with(&curprefix);
            sugg.sort();
            sugg.truncate(3);
            res.push(sugg);
        }
        
        res
    }
}