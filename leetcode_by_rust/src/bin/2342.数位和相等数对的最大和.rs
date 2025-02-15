/*
 * @lc app=leetcode.cn id=2342 lang=rust
 *
 * [2342] 数位和相等数对的最大和
 *
 * https://leetcode.cn/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/
 *
 * algorithms
 * Medium (53.79%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 23.1K
 * Testcase Example:  '[18,43,36,13,7]'
 *
 * 给你一个下标从 0 开始的数组 nums ，数组中的元素都是 正 整数。请你选出两个下标 i 和 j（i != j），且 nums [i] 的数位和 与
 * nums [j] 的数位和相等。
 * 
 * 请你找出所有满足条件的下标 i 和 j ，找出并返回 nums [i] + nums [j] 可以得到的 最大值 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [18,43,36,13,7]
 * 输出：54
 * 解释：满足条件的数对 (i, j) 为：
 * - (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
 * - (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
 * 所以可以获得的最大和是 54 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [10,12,19,14]
 * 输出：-1
 * 解释：不存在满足条件的数对，返回 -1 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn maximum_sum(nums: Vec<i32>) -> i32 {
        fn get_sum(mut num: i32) -> i32 {
            let mut sum = 0;
            while num > 0 {
                sum += num % 10;
                num /= 10;
            }
            sum
        }
        let mut map: std::collections::HashMap<i32, i32> = std::collections::HashMap::new();
        let mut ans = -1;
        for num in nums {
            let sum = get_sum(num);
            if let Some(&v) = map.get(&sum) {
                ans = ans.max(v + num);
                map.insert(sum, v.max(num));
            } else {
                map.insert(sum, num);
            }
        }
        ans
    }
}
// @lc code=end

