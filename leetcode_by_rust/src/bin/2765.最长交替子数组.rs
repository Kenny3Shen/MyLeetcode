/*
 * @lc app=leetcode.cn id=2765 lang=rust
 *
 * [2765] 最长交替子数组
 */

// @lc code=start
impl Solution {
    pub fn alternating_subarray(nums: Vec<i32>) -> i32 {
        let mut res = -1;
        let n = nums.len();
        for first_index in 0..n {
            for i in (first_index + 1)..n {
                let cur_len = i - first_index + 1;
                if nums[i] - nums[first_index] == (cur_len - 1) as i32 % 2{
                    res = res.max(cur_len as i32)
                } else {
                    break;
                }
            }
        }
        res
    }
}
// @lc code=end
