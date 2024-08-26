/*
 * @lc app=leetcode.cn id= 面试题 01.06 lang=rust
 * @lcpr version=30204
 *
 * [ 面试题 01.06] 字符串压缩
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn compress_string(s: String) -> String {
        let mut last_char = match s.len() {
            0 => return s,
            _ => s.chars().next().unwrap(),
        };
        let mut res = String::new();
        let mut cnt = 0;
        for c in s.chars() {
            match c == last_char {
                true => cnt += 1,
                false => {
                    res.push(last_char);
                    res.push_str(&cnt.to_string());
                    last_char = c;
                    cnt = 1;
                }
            }
        }
        res.push(last_char);
        res.push_str(&cnt.to_string());
        if res.len() < s.len() {
            res
        } else {
            s
        }
    }
}
// @lc code=end

/*
// @lcpr case=start
// "aabcccccaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abbccd"\n
// @lcpr case=end

 */
