impl Solution {
    pub fn erase_overlap_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_by_key(|x| x[1]);

        let mut res = 0;
        let mut prev_end = intervals[0][1];

        for interval in intervals.iter().skip(1) {
            let (start, end) = (interval[0], interval[1]);
            if start >= prev_end {
                prev_end = end;
            } else {
                res += 1;
            }
        }

        res
    }
}
