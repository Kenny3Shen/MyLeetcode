/*
 * @lc app=leetcode.cn id=3192 lang=rust
 * @lcpr version=30204
 *
 * [3192] 使二进制数组全部等于 1 的最少操作次数 II
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut operation = 0;
        for num in nums {
            if num == (operation % 2) {
                operation += 1;
            }
        }
        operation
        // let mut operation = 0;
        // for i in (0..nums.len() - 1).rev() {
        //     if nums[i] != nums[i + 1] {
        //         operation += 1;
        //     }
        // }
        // if nums[0] == 1 {
        //     operation
        // } else {
        //     operation + 1
        // }
    }
}
// @lc code=end



/*
// @lcpr case=start
// [0,1,1,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,0,0,0]\n
// @lcpr case=end

 */

