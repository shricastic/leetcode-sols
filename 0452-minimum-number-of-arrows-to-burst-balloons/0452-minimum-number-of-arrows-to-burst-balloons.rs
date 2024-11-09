impl Solution {
    pub fn find_min_arrow_shots(mut points: Vec<Vec<i32>>) -> i32 {
        if points.len()==0 { return 0;}

        let mut n = points.len();
        points.sort();
        
        let mut prev_end = points[0][1];
        let mut res = 1;
        
        for point in points.iter().skip(1) {
            let (sp, ep) = (point[0], point[1]);
            if sp > prev_end {
                res += 1;
                prev_end = ep;
            } else {
                prev_end = prev_end.min(ep);
            }
        }
        res
    }
}