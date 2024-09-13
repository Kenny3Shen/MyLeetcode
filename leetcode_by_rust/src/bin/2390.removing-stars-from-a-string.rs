/*
 * @lc app=leetcode.cn id=2390 lang=rust
 * @lcpr version=30204
 *
 * [2390] 从字符串中移除星号
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn remove_stars(s: String) -> String {
        let mut res = String::new();
        for c in s.chars() {
            if c != '*' {
                res.push(c);
            } else {
                res.pop();
            }
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// "leet**cod*e"\n
// @lcpr case=end

// @lcpr case=start
// "erase*****"\n
// @lcpr case=end

 */

