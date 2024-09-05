/*
 * @lc app=leetcode.cn id=3174 lang=rust
 * @lcpr version=30204
 *
 * [3174] 清除数字
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn clear_digits(s: String) -> String {
        let mut stack = Vec::new();
        for c in s.chars() {
            match c {
                '0'..='9' => {
                    stack.pop();
                }
                _ => {
                    stack.push(c);
                }
            }
        }
        stack.iter().collect()
    }
}
// @lc code=end



/*
// @lcpr case=start
// "abc"\n
// @lcpr case=end

// @lcpr case=start
// "cb34"\n
// @lcpr case=end

 */

