use std::collections::HashMap;

#[derive(Default)]
struct TrieNode {
    children: HashMap<char, TrieNode>,
    end_word: bool,
}

struct Trie {
    root: TrieNode,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Trie {

    fn new() -> Self {
        Trie { root : TrieNode::default(), }
    }
    
    fn insert(&mut self, word: String) {
        let mut node = &mut self.root;
        
        for c in word.chars() {
            if !node.children.contains_key(&c) {
                node.children.insert(c, TrieNode::default());
            }
            node = node.children.get_mut(&c).unwrap();
        }
        
        node.end_word = true
    }
    
    fn search(&mut self, word: String) -> bool {
        let mut node = &mut self.root;
        
        for c in word.chars() {
            if let Some(child) = node.children.get_mut(&c) {
                node = child;
            } else {
                return false;
            }
        }
        
        node.end_word
    }
    
    fn starts_with(&mut self, prefix: String) -> bool {
        let mut node = &mut self.root;
        
        for c in prefix.chars() {
            if !node.children.contains_key(&c) { return false; }
            node = node.children.get_mut(&c).unwrap();
        }
        
        true
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie::new();
 * obj.insert(word);
 * let ret_2: bool = obj.search(word);
 * let ret_3: bool = obj.starts_with(prefix);
 */