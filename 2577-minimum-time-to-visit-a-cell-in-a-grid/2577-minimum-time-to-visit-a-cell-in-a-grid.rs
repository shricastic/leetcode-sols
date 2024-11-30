use std::collections::{HashSet, BinaryHeap};
use std::cmp::Reverse;

impl Solution {
    pub fn minimum_time(grid: Vec<Vec<i32>>) -> i32 {
        if grid[0][1] > 1 && grid[1][0] > 1 {
            return -1;
        }

        let (m, n) = (grid.len(), grid[0].len());
        let mut q = BinaryHeap::from([Reverse((grid[0][0], 0, 0))]);
        let mut visited = HashSet::from([(0, 0)]);
        let mut res = -1;

        while let Some(Reverse((time, x, y))) = q.pop() {
            if x == m - 1 && y == n - 1 {
                res = time;
                break;
            }

            for (dx, dy) in [(0, 1), (1, 0), (0, -1), (-1, 0)] {
                let (nx, ny) = ((x as i32 + dx) as usize, (y as i32 + dy) as usize);
                if nx < m && ny < n && !visited.contains(&(nx, ny)) {
                    visited.insert((nx, ny));
                    let move_time = if (grid[nx][ny] - time) % 2 == 0 { 1 } else { 0 };
                    q.push(Reverse(((time + 1).max(grid[nx][ny] + move_time), nx, ny)));
                }
            }
        }

        res
    }
}