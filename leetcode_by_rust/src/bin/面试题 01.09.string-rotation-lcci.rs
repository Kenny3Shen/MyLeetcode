/*
 * @lc app=leetcode.cn id= 面试题 01.09 lang=rust
 * @lcpr version=30204
 *
 * [ 面试题 01.09] 字符串轮转
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn is_fliped_string(s1: String, s2: String) -> bool {
        if s1.len() != s2.len() {
            return false;
        }
        let s1 = s1.to_owned() + &s1;
        s1.contains(&s2)
    }
}
// @lc code=end



/*
// @lcpr case=start
// "waterbottle"\n"erbottlewat"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aba"\n
// @lcpr case=end

 */

