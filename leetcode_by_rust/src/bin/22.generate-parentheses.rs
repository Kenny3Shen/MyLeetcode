/*
 * @lc app=leetcode.cn id=22 lang=rust
 * @lcpr version=30204
 *
 * [22] 括号生成
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        fn back_trace(s: String, n: usize, left: usize, right: usize, res: &mut Vec<String>) {
            if left == n && right == n {
                res.push(s);
                return;
            }
            if left < n {
                back_trace(s.clone() + "(", n, left + 1, right, res);
            }
            if right < left {
                back_trace(s.clone() + ")", n, left, right + 1, res);
            }
        }

        let mut res = vec![];
        back_trace(String::new(), n as usize, 0, 0, &mut res);
        res
    }
}
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
