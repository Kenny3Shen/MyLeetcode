/*
 * @lc app=leetcode.cn id=3206 lang=rust
 * @lcpr version=30204
 *
 * [3206] 交替组 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn number_of_alternating_groups(mut colors: Vec<i32>) -> i32 {
        let mut res = 0;
        colors.push(colors[0]);
        colors.push(colors[1]);
        for i in 0..colors.len() - 2 {
            if colors[i + 1] != colors[i] && colors[i + 1] != colors[i + 2] {
                res += 1;
            }
        }
        res
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,0,1]\n
// @lcpr case=end

 */
