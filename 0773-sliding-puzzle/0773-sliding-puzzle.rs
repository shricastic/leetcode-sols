use std::collections::*;

impl Solution {
    pub fn sliding_puzzle(b: Vec<Vec<i32>>) -> i32 {
        let (mut visited, mut q) = (HashSet::new(), VecDeque::new());
        q.push_back((0, (0..6).map(|i| b[i / 3][i % 3]).collect::<Vec<_>>()));
        while let Some((step, s)) = q.pop_front() {
            let key = s.iter().fold(0, |r, t| r * 10 + t);
            if key == 123450 { return step }
            if !visited.insert(key) { continue }
            let i = s.iter().position(|&x| x == 0).unwrap();
            for j in [i - 3, i + 1, i + 3, i - 1] {
                if 0 <= j && j < 6 && (i / 3 == j / 3 || i % 3 == j % 3) {
                    let mut ss = s.clone(); ss[j] = s[i]; ss[i] = s[j];
                    q.push_back((step + 1, ss));
                }
            }
        }; -1
    }
}