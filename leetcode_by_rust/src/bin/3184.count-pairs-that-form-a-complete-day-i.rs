/*
 * @lc app=leetcode.cn id=3184 lang=rust
 * @lcpr version=30204
 *
 * [3184] 构成整天的下标对数目 I
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn count_complete_day_pairs(hours: Vec<i32>) -> i32 {
        let mut res = 0;
        for i in 0..hours.len() {
            for j in i+1..hours.len() {
                if (hours[i] + hours[j]) % 24 == 0 {
                    res += 1;
                }
            }
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [12,12,30,24,24]\n
// @lcpr case=end

// @lcpr case=start
// [72,48,24,3]\n
// @lcpr case=end

 */

