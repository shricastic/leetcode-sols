impl Solution {
    pub fn shortest_distance_after_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let n = n as usize;
        let mut graph = vec![vec![]; n];
        let mut ans = vec![];

        for i in 0..(n - 1) {
            graph[i].push(i + 1);
        }

        for query in queries {
            let (u, v) = (query[0] as usize, query[1] as usize);
            graph[u].push(v);

            let mut dp = vec![0; n];
            dp[n - 1] = 0;
            for i in (0..(n - 1)).rev() {
                dp[i] = graph[i].iter().fold(n, |acc, &n| acc.min(dp[n] + 1));
            }
            ans.push(dp[0] as i32);
        }
        ans
    }
}