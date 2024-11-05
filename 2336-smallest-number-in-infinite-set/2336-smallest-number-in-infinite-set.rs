use std::collections::{BinaryHeap, HashSet};
use std::cmp::Reverse;

struct SmallestInfiniteSet {
    pq: BinaryHeap<Reverse<i32>>,
    set: HashSet<i32>,
}

impl SmallestInfiniteSet {
    fn new() -> Self {
        let mut pq = BinaryHeap::new();
        let mut set = HashSet::new();
        
        for i in 1..=1000 {
            pq.push(Reverse(i));
            set.insert(i);
        }

        SmallestInfiniteSet { pq, set }
    }

    fn pop_smallest(&mut self) -> i32 {
        if let Some(Reverse(smallest)) = self.pq.pop() {
            self.set.remove(&smallest);
            smallest
        } else {
            -1
        }
    }

    fn add_back(&mut self, num: i32) {
        if self.set.insert(num) {  // Only add if not present
            self.pq.push(Reverse(num));
        }
    }
}
