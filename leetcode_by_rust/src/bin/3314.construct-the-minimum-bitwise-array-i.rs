/*
 * @lc app=leetcode.cn id=3314 lang=rust
 * @lcpr version=30204
 *
 * [3314] 构造最小位运算数组 I
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut res = vec![-1; n];
        for i in 0..n {
            for j in 0..nums[i] {
                if j | (j + 1) == nums[i] {
                    res[i] = j;
                    break;
                }
            }
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [2,3,5,7]\n
// @lcpr case=end

// @lcpr case=start
// [11,13,31]\n
// @lcpr case=end

 */

