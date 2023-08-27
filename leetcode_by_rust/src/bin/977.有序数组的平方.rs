/*
 * @lc app=leetcode.cn id=977 lang=rust
 *
 * [977] 有序数组的平方
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (67.90%)
 * Likes:    865
 * Dislikes: 0
 * Total Accepted:    567.5K
 * Total Submissions: 835.9K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 *
 * 示例 2：
 *
 *
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 10^4
 * -10^4
 * nums 已按 非递减顺序 排序
 *
 *
 *
 *
 * 进阶：
 *
 *
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
 *
 *
 */

use std::vec;

// @lc code=start
impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        // let mut nums = nums.into_iter().map(|x| x * x).collect::<Vec<i32>>();
        // nums.sort_unstable();
        // nums
        if nums.len() == 1 {
            return vec![nums[0] * nums[0]];
        }

        let mut location = nums.len();
        let mut res = vec![0; location];
        let (mut left, mut right) = (0, location - 1);
        let (mut i, mut j) = (nums[left] * nums[left], nums[right] * nums[right]);
        while left < right {
            location -= 1;
            if i > j {
                res[location] = i;
                left += 1;
                i = nums[left] * nums[left];
            } else {
                res[location] = j;
                right -= 1;
                j = nums[right] * nums[right];
            }
        }
        res[0] = j;
        res
    }
}
// @lc code=end
