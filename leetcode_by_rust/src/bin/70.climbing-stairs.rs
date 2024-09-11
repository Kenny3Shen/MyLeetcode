/*
 * @lc app=leetcode.cn id=70 lang=rust
 * @lcpr version=30204
 *
 * [70] 爬楼梯
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        // let mut dp = vec![0; n as usize + 1];
        // dp[0] = 1;
        // dp[1] = 1;
        // for i in 2..=n as usize {
        //     dp[i] = dp[i - 1] + dp[i - 2];
        // }
        // dp[n as usize]

        let mut pre = 1;
        let mut cur = 1;
        for _ in 2..=n {
            let tmp = cur;
            cur += pre;
            pre = tmp;
        }
        cur
    }
}
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

