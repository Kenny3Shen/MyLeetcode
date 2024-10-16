/*
 * @lc app=leetcode.cn id=3193 lang=rust
 * @lcpr version=30204
 *
 * [3193] 统计逆序对的数目
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
use std::collections::HashMap;
const MOD: i64 = 1_000_000_007;

impl Solution {
    pub fn number_of_permutations(n: i32, requirements: Vec<Vec<i32>>) -> i32 {
        let mut req_map: HashMap<i32, i32> = HashMap::new();
        req_map.insert(0, 0);
        let mut max_cnt = 0;
        for i in 0..requirements.len() {
            let end = requirements[i][0];
            let cnt = requirements[i][1];
            req_map.insert(end, cnt);
            max_cnt = max_cnt.max(cnt);
        }
        if req_map[&0] != 0 {
            return 0;
        }
        let mut dp = vec![vec![-1; (max_cnt + 1) as usize]; n as usize];

        fn dfs(end: usize, cnt: i32, req_map: &HashMap<i32, i32>, dp: &mut Vec<Vec<i64>>) -> i64 {
            if cnt < 0 {
                return 0;
            }
            if end == 0 {
                return 1;
            }
            if dp[end][cnt as usize] != -1 {
                return dp[end][cnt as usize];
            }
            if let Some(&r) = req_map.get(&(end as i32 - 1)) {
                if r <= cnt && cnt <= (end as i32 + r) {
                    dp[end][cnt as usize] = dfs(end - 1, r, req_map, dp);
                    return dp[end][cnt as usize];
                }
                return 0;
            } else {
                if cnt > end as i32 {
                    dp[end][cnt as usize] = (dfs(end, cnt - 1, req_map, dp)
                        - dfs(end - 1, cnt - 1 - end as i32, req_map, dp)
                        + dfs(end - 1, cnt, req_map, dp)
                        + MOD) % MOD;
                } else {
                    dp[end][cnt as usize] = (dfs(end, cnt - 1, req_map, dp)
                        + dfs(end - 1, cnt, req_map, dp)) % MOD;
                }
                return dp[end][cnt as usize];
            }
        }

        dfs(n as usize - 1, *req_map.get(&(n - 1)).unwrap(), &req_map, &mut dp) as i32
    }
}
// @lc code=end



/*
// @lcpr case=start
// 3\n[[2,2],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[2,2],[1,1],[0,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,0],[1,0]]\n
// @lcpr case=end

 */

