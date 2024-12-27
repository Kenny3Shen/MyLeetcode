/*
 * @lc app=leetcode.cn id=3010 lang=rust
 *
 * [3010] 将数组分成最小总代价的子数组 I
 *
 * https://leetcode.cn/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/
 *
 * algorithms
 * Easy (72.73%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 4.4K
 * Testcase Example:  '[1,2,3,12]'
 *
 * 给你一个长度为 n 的整数数组 nums 。
 * 
 * 一个数组的 代价 是它的 第一个 元素。比方说，[1,2,3] 的代价是 1 ，[3,4,1] 的代价是 3 。
 * 
 * 你需要将 nums 分成 3 个 连续且没有交集 的子数组。
 * 
 * 请你返回这些子数组的 最小 代价 总和 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,12]
 * 输出：6
 * 解释：最佳分割成 3 个子数组的方案是：[1] ，[2] 和 [3,12] ，总代价为 1 + 2 + 3 = 6 。
 * 其他得到 3 个子数组的方案是：
 * - [1] ，[2,3] 和 [12] ，总代价是 1 + 2 + 12 = 15 。
 * - [1,2] ，[3] 和 [12] ，总代价是 1 + 3 + 12 = 16 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,4,3]
 * 输出：12
 * 解释：最佳分割成 3 个子数组的方案是：[5] ，[4] 和 [3] ，总代价为 5 + 4 + 3 = 12 。
 * 12 是所有分割方案里的最小总代价。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [10,3,1,1]
 * 输出：12
 * 解释：最佳分割成 3 个子数组的方案是：[10,3] ，[1] 和 [1] ，总代价为 10 + 1 + 1 = 12 。
 * 12 是所有分割方案里的最小总代价。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= n <= 50
 * 1 <= nums[i] <= 50
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn minimum_cost(nums: Vec<i32>) -> i32 {
        let (mut min_1, mut min_2) = (i32::MAX, i32::MAX);
        let n = nums.len();
        for &num in nums.iter().skip(1) {
            if num < min_1 {
                min_2 = min_1;
                min_1 = num;
            } else if num < min_2 {
                min_2 = num;
            }
        }
        nums[0] + min_1 + min_2
    }
}
// @lc code=end

