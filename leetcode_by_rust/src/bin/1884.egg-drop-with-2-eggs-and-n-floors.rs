/*
 * @lc app=leetcode.cn id=1884 lang=rust
 * @lcpr version=30204
 *
 * [1884] 鸡蛋掉落 - 两枚鸡蛋
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn two_egg_drop(n: i32) -> i32 {
        // 如果鸡蛋碎了，说明答案为 [0, k-1], 但只剩下一颗鸡蛋，则要遍历 0..k-1
        // 如果鸡蛋没碎，说明答案为 [k, n], 因为有两颗鸡蛋，等价与一栋有 i-k 层建筑的子问题，需要 dp[i-k] 次
        let n = n as usize;
        let mut dp = vec![i32::MAX / 2; n + 1];
        dp[0] = 0;
        for i in 1..(n + 1) {
            for k in 1..(i + 1) {
                dp[i] = dp[i].min(1 + dp[i - k].max(k as i32 - 1));
            }
        }
        dp[n]
        // ((-1.0 + (1.0 + 8.0 * n as f64).sqrt()) / 2.0).ceil() as i32
    }
}
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 100\n
// @lcpr case=end

 */

