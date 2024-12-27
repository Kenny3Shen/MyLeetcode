/*
 * @lc app=leetcode.cn id=2078 lang=rust
 *
 * [2078] 两栋颜色不同且距离最远的房子
 */

// @lc code=start
impl Solution {
    pub fn max_distance(colors: Vec<i32>) -> i32 {
        let mut ans: i32 = 0;
        for i in 0..colors.len() {
            let mut j = colors.len() - 1;
            while (colors[i] == colors[j]) {
                j -= 1;
            }
            ans = ans.max(j as i32 - i as i32)
        }
        ans
    }
}
// @lc code=end
