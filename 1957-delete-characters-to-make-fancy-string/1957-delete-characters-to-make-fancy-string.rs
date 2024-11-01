impl Solution {
    pub fn make_fancy_string(s: String) -> String {
        let mut res = String::new();
        let mut prev_char = '\0';
        let mut count = 0;

        for c in s.chars() {
            if c == prev_char {
                count += 1;
            } else {
                count = 1;
            }

            if count < 3 {
                res.push(c);
            }
            prev_char = c;
        }

        res
    }
}
