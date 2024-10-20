/*
 * @lc app=leetcode.cn id=910 lang=rust
 * @lcpr version=30204
 *
 * [910] 最小差值 II
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn smallest_range_ii(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();
        let (mi, ma) = (nums[0], nums[nums.len() - 1]);
        let mut res = ma - mi;
        for i in 0..nums.len() - 1 {
            let (a, b) = (nums[i], nums[i + 1]);
            res = res.min((ma - k).max(a + k) - (mi + k).min(b - k));
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

// @lcpr case=start
// [0,10]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,3,6]\n3\n
// @lcpr case=end

 */

