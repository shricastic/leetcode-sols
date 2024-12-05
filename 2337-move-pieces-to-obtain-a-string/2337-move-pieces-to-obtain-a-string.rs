impl Solution {
    pub fn can_change(start: String, target: String) -> bool {
        let start: Vec<char> = start.chars().collect();
        let target: Vec<char> = target.chars().collect();
        let mut l = 0;
        let mut m = 0;
        let n = start.len();
        let mut tar_space = 0;
        let mut sta_space = 0;

        while l < n && m < n {
            while l < n && target[l] == '_' {
                tar_space += 1;
                l += 1;
            }
            while m < n && start[m] == '_' {
                sta_space += 1;
                m += 1;
            }

            if l < n && m < n {
                if target[l] != start[m] {
                    return false;
                }
                if target[l] == 'L' {
                    if tar_space > sta_space {
                        return false;
                    }
                } else if sta_space > tar_space {
                    return false;
                }
                l += 1;
                m += 1;
            }
        }

        // Check remaining characters
        while l < n {
            if target[l] != '_' {
                return false;
            }
            l += 1;
        }
        while m < n {
            if start[m] != '_' {
                return false;
            }
            m += 1;
        }

        true
    }
}
