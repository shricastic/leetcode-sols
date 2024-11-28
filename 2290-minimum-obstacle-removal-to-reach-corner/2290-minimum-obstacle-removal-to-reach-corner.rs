use std::{cmp::Reverse, collections::BinaryHeap};
impl Solution {
    pub fn minimum_obstacles(mut grid: Vec<Vec<i32>>) -> i32 {
        let (m, n) = (grid.len() - 1, grid[0].len() - 1);
        let mut queue = BinaryHeap::from([Reverse((0, 0, 0))]);
        while let Some(Reverse((d, r, c))) = queue.pop() {
            if (r, c) == (m, n) {
                return d;
            }
            for &(rr, cc) in &[(r.wrapping_sub(1), c), (r + 1, c), (r, c.wrapping_sub(1)), (r, c + 1)] {
                if rr <= m && cc <= n && grid[rr][cc] < 2 {
                    queue.push(Reverse((d + grid[rr][cc], rr, cc)));
                    grid[rr][cc] = 2;
                }
            }
        }
        unreachable!()
    }
}