/*
 * @lc app=leetcode.cn id=3216 lang=rust
 * @lcpr version=30204
 *
 * [3216] 交换后字典序最小的字符串
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn get_smallest_string(s: String) -> String {
        let mut s = s.into_bytes();
        for i in 1..s.len() {
            let (x, y) = (s[i - 1], s[i]);
            if x > y && x % 2 == y % 2 {
                (s[i - 1], s[i]) = (y, x);
                break;
            }
        }
        String::from_utf8(s).unwrap()
    }
}
// @lc code=end



/*
// @lcpr case=start
// "45320"\n
// @lcpr case=end

// @lcpr case=start
// "001"\n
// @lcpr case=end

 */

