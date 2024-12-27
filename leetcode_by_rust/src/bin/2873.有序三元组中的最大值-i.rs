/*
 * @lc app=leetcode.cn id=2873 lang=rust
 *
 * [2873] 有序三元组中的最大值 I
 *
 * https://leetcode.cn/problems/maximum-value-of-an-ordered-triplet-i/description/
 *
 * algorithms
 * Easy (54.42%)
 * Likes:    15
 * Dislikes: 0
 * Total Accepted:    5.5K
 * Total Submissions: 10.1K
 * Testcase Example:  '[12,6,1,2,7]'
 *
 * 给你一个下标从 0 开始的整数数组 nums 。
 *
 * 请你从所有满足 i <j < k 的下标三元组 (i, j, k) 中，找出并返回下标三元组的最大值。如果所有满足条件的三元组的值都是负数，则返回 0
 * 。
 *
 * 下标三元组 (i, j, k) 的值等于 (nums [i] - nums [j]) * nums [k] 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [12,6,1,2,7]
 * 输出：77
 * 解释：下标三元组 (0, 2, 4) 的值是 (nums [0] - nums [2]) * nums [4] = 77 。
 * 可以证明不存在值大于 77 的有序下标三元组。
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,10,3,4,19]
 * 输出：133
 * 解释：下标三元组 (1, 2, 4) 的值是 (nums [1] - nums [2]) * nums [4] = 133 。
 * 可以证明不存在值大于 133 的有序下标三元组。
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [1,2,3]
 * 输出：0
 * 解释：唯一的下标三元组 (0, 1, 2) 的值是一个负数，(nums [0] - nums [1]) * nums [2] = -3 。因此，答案是 0
 * 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= nums.length <= 100
 * 1 <= nums[i] <= 10^6
 *
 *
 */

// @lc code=start
impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        /* // enumerate all the triplet
        let mut res = 0;
        let n = nums.len();
        for i in 0..n {
            for j in i + 1..n {
                for k in j + 1..n {
                    res = res.max((nums[i] - nums[j]) as i64 * nums[k] as i64);
                }
            }
        }
        res.max(0) */

        /* // maintain the suffix_max and prefix_max
        let n = nums.len();
        let mut suffix_max = vec![0; n + 1];
        for i in (0..n).rev() {
            suffix_max[i] = suffix_max[i + 1].max(nums[i]);
        }
        let mut res = 0;
        let mut prefix_max = nums[0];
        for i in 1..n - 1 {
            prefix_max = prefix_max.max(nums[i - 1]);
            res = res.max((prefix_max - nums[i]) as i64 * suffix_max[i + 1] as i64);
        }
        res.max(0) */

        // maintain the max_diff of nums[i] - nums[j]
        let n = nums.len();
        let (mut max_diff, mut pre_max, mut res) = (0, 0, 0);
        for x in nums.iter().map(|&x| x as i64) {
            res = res.max(max_diff * x);
            max_diff = max_diff.max(pre_max - x);
            pre_max = pre_max.max(x);
        }
        res.max(0)
    }
}
// @lc code=end
