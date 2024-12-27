/*
 * @lc app=leetcode.cn id=908 lang=rust
 * @lcpr version=30204
 *
 * [908] 最小差值 I
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn smallest_range_i(nums: Vec<i32>, k: i32) -> i32 {
        let mx = nums.iter().max().unwrap();
        let mn = nums.iter().min().unwrap();
        (mx - mn - 2 * k).max(0)
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

