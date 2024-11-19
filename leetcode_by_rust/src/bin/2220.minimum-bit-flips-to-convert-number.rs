/*
 * @lc app=leetcode.cn id=2220 lang=rust
 * @lcpr version=30204
 *
 * [2220] 转换数字的最少位翻转次数
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_bit_flips(start: i32, goal: i32) -> i32 {
        (start ^ goal).count_ones() as i32
    }
}
// @lc code=end



/*
// @lcpr case=start
// 10\n7\n
// @lcpr case=end

// @lcpr case=start
// 3\n4\n
// @lcpr case=end

 */

