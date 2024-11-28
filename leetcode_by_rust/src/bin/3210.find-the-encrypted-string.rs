/*
 * @lc app=leetcode.cn id=3210 lang=rust
 * @lcpr version=30204
 *
 * [3210] 找出加密后的字符串
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn get_encrypted_string(s: String, k: i32) -> String {
        let n = s.len();
        let k = k as usize % n ;
        let mut res = s.clone() + &s;
        res[k..k + n].to_string()
    }
}
// @lc code=end



/*
// @lcpr case=start
// "dart"\n3\n
// @lcpr case=end

// @lcpr case=start
// "aaa"\n1\n
// @lcpr case=end

 */

