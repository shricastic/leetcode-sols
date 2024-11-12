impl Solution {
    pub fn maximum_beauty(items: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
        let mut items = items;
        let mut ans = vec![0; queries.len()];

        items.sort_by_key(|item| item[0]);

        let mut max_beauty = items[0][1];
        for item in items.iter_mut() {
            max_beauty = max_beauty.max(item[1]);
            item[1] = max_beauty;
        }

        for (i, &query) in queries.iter().enumerate() {
            ans[i] = Solution::binary_search(&items, query);
        }

        ans
    }

    fn binary_search(items: &Vec<Vec<i32>>, target_price: i32) -> i32 {
        let mut left = 0;
        let mut right = items.len() as i32 - 1;
        let mut max_beauty = 0;

        while left <= right {
            let mid = (left + right) / 2;
            let mid_price = items[mid as usize][0];

            if mid_price > target_price {
                right = mid - 1;
            } else {
                max_beauty = max_beauty.max(items[mid as usize][1]);
                left = mid + 1;
            }
        }

        max_beauty
    }
}
