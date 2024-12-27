/*
 * @lc app=leetcode.cn id=46 lang=rust
 *
 * [46] 全排列
 *
 * https://leetcode.cn/problems/permutations/description/
 *
 * algorithms
 * Medium (78.86%)
 * Likes:    2565
 * Dislikes: 0
 * Total Accepted:    868.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [0,1]
 * 输出：[[0,1],[1,0]]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1]
 * 输出：[[1]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 *
 *
 */

// @lc code=start
pub fn back_tracking(nums: &mut Vec<i32>, begin: usize, res: &mut Vec<Vec<i32>>) {
    if begin == nums.len() {
        res.push(nums.to_vec());
    }
    for i in begin..nums.len() {
        nums.swap(i, begin);
        Self::back_tracking(nums, begin + 1, res);
        nums.swap(i, begin);
    }
}
impl Solution {
    pub fn permute(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        back_tracking(&mut nums, 0, &mut res);
        res
    }
}
// @lc code=end
