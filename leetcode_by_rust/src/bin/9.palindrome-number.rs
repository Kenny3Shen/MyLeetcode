/*
 * @lc app=leetcode.cn id=9 lang=rust
 * @lcpr version=30204
 *
 * [9] 回文数
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }
        let mut y = 0;
        let mut z = x;
        while z != 0 {
            y = y * 10 + z % 10;
            z = z / 10;
        }
        x == y
    }
}
// @lc code=end



/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

