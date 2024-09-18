/*
 * @lc app=leetcode.cn id=2414 lang=rust
 * @lcpr version=30204
 *
 * [2414] 最长的字母序连续子字符串的长度
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn longest_continuous_substring(s: String) -> i32 {
        let mut res = 1;
        let s = s.as_bytes();
        let n = s.len();
        let mut cur = 1;
        for i in 1..n {
            if s[i] - s[i - 1] == 1{
                cur += 1;
            } else {
                cur = 1;
            }
            res = res.max(cur);
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// "abacaba"\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n
// @lcpr case=end

 */

