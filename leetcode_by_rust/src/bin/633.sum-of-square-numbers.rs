/*
 * @lc app=leetcode.cn id=633 lang=rust
 * @lcpr version=30204
 *
 * [633] 平方数之和
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn judge_square_sum(c: i32) -> bool {
        let mut a: i64 = 0;
        while a * a <= c as i64 {
            let b_square = (c as i64) - a * a;
            let b = (b_square as f64).sqrt() as i64;
            if b * b == b_square {
                return true;
            }
            a += 1;
        }
        false
    }
}
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

