impl Solution {
    pub fn erase_overlap_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort();

        let mut res = 0;
        let mut prev_end = intervals[0][1];

        for interval in intervals.iter().skip(1) {
            let (start, end) = (interval[0], interval[1]);
            if start < prev_end {
                res += 1;
                prev_end = prev_end.min(end);
            } else {
                prev_end = end;
            }
        }

        res
    }
}
