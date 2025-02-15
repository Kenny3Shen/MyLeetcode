/*
 * @lc app=leetcode.cn id=128 lang=rust
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (54.36%)
 * Likes:    1807
 * Dislikes: 0
 * Total Accepted:    441.5K
 * Total Submissions: 817.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let mut set: std::collections::HashSet<i32> = nums.into_iter().collect();
        let mut res = 0;
        // 若存在 x-1，则 x 不可能是最长连续序列的起点 
        for &num in set.iter() {
            if !set.contains(&(num - 1)) {
                let mut cur_len = 1;
                let mut cur_num = num;
                while set.contains(&(cur_num + 1)) {
                    cur_num += 1;
                    cur_len += 1;
                }
                res = res.max(cur_len)
            }
        }
        res
    }
}
// @lc code=end

