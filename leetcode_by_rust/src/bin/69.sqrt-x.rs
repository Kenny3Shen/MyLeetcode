/*
 * @lc app=leetcode.cn id=69 lang=rust
 * @lcpr version=30204
 *
 * [69] x 的平方根 
 */


// @lcpr-template-start

use std::intrinsics::expf64;

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let (mut left, mut right) = (0, x);
        let mut ans = -1;
        while (left <= right) {
            let mid = left + (right - left) / 2;
            if mid as i64 * mid as i64 <= x as i64 {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        ans
    }
}
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 8\n
// @lcpr case=end

 */

