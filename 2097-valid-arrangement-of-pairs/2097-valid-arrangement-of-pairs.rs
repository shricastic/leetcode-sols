use std::collections::HashMap;

impl Solution {
    pub fn valid_arrangement(pairs: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut adj = HashMap::<i32, Vec<i32>>::new();
        let mut deg = HashMap::<i32, i32>::new();
        for v in pairs.iter() {
            adj.entry(v[1]).or_insert(Vec::new()).push(v[0]);
            adj.entry(v[0]).or_insert(Vec::new());
            *deg.entry(v[1]).or_insert(0) += 1;
            *deg.entry(v[0]).or_insert(0) -= 1;
        }
        let last = *deg.iter().find(|&(_, &x)| x == 1)
            .or(deg.iter().next())
            .unwrap().0;
        let mut ans = Vec::<Vec<i32>>::with_capacity(pairs.len());
        Self::arrange(last, &mut ans, &mut adj);
        ans
    }

    fn arrange(curr: i32, ans: &mut Vec<Vec<i32>>, adj: &mut HashMap<i32, Vec<i32>>) {
        while let Some(prev) = adj.get_mut(&curr).unwrap().pop() {
            Self::arrange(prev, ans, adj);
            ans.push(vec![prev, curr]);
        }
    }
}