impl Solution {
    pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        let mut min_length = i32::MAX;
        let mut window_start = 0;
        let mut window_end = 0;
        let mut bit_counts = vec![0; 32];  

        while window_end < nums.len() {
            Self::update_bit_counts(&mut bit_counts, nums[window_end], 1);

            while window_start <= window_end && Self::convert_bit_counts_to_number(&bit_counts) >= k {
                min_length = min_length.min((window_end - window_start + 1) as i32);

                Self::update_bit_counts(&mut bit_counts, nums[window_start], -1);
                window_start += 1;
            }

            window_end += 1;
        }

        if min_length == i32::MAX {
            -1
        } else {
            min_length
        }
    }

    fn update_bit_counts(bit_counts: &mut Vec<i32>, number: i32, delta: i32) {
        for bit_position in 0..32 {
            if (number >> bit_position) & 1 == 1 {
                bit_counts[bit_position] += delta;
            }
        }
    }

    fn convert_bit_counts_to_number(bit_counts: &Vec<i32>) -> i32 {
        let mut result = 0;
        for bit_position in 0..32 {
            if bit_counts[bit_position] > 0 {
                result |= 1 << bit_position;
            }
        }
        result
    }
}
