/*
 * @lc app=leetcode.cn id=3185 lang=rust
 * @lcpr version=30204
 *
 * [3185] 构成整天的下标对数目 II
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn count_complete_day_pairs(hours: Vec<i32>) -> i64 {
        let mut ans: i64 = 0;
        let mut cnt = vec![0; 24];
        for hour in hours {
            ans += cnt[(24 - hour % 24) as usize % 24] as i64;
            cnt[hour as usize % 24] += 1;
        }
        ans
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

