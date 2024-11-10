/*
 * @lc app=leetcode.cn id=1547 lang=rust
 * @lcpr version=30204
 *
 * [1547] 切棍子的最小成本
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
use std::cmp::min;

impl Solution {
    pub fn min_cost(n: i32, cuts: Vec<i32>) -> i32 {
        let mut cuts = cuts;
        cuts.push(0);
        cuts.push(n);
        cuts.sort();
        let m = cuts.len();
        let mut f = vec![vec![0; m]; m];

        for i in (0..m).rev() {
            for j in i + 2..m {
                f[i][j] = i32::MAX;
                for k in i + 1..j {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
                f[i][j] += cuts[j] - cuts[i];
            }
        }

        f[0][m - 1]
    }
}
// @lc code=end



/*
// @lcpr case=start
// 7\n[1,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// 9\n[5,6,1,4,2]\n
// @lcpr case=end

 */

