/*
 * @lc app=leetcode.cn id=2974 lang=rust
 * @lcpr version=30204
 *
 * [2974] 最小数字游戏
 */


// @lcpr-template-start

use core::num;

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn number_game(mut nums: Vec<i32>) -> Vec<i32> {
        // let mut nums = nums;
        // nums.sort();
        // let mut res = vec![];
        // let n = nums.len();
        // let mut i = 0;
        // while i < nums.len() {
        //     res.push(nums[i + 1]);
        //     res.push(nums[i]);
        //     i += 2;
        // }
        // res
        nums.sort();
        for i in (0..nums.len()).step_by(2) {
            nums.swap(i, i + 1);
        }
        nums
    }
}
// @lc code=end



/*
// @lcpr case=start
// [5,4,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,5]\n
// @lcpr case=end

 */

