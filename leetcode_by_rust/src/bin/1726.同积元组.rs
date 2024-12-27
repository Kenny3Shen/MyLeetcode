/*
 * @lc app=leetcode.cn id=1726 lang=rust
 *
 * [1726] 同积元组
 *
 * https://leetcode.cn/problems/tuple-with-same-product/description/
 *
 * algorithms
 * Medium (52.46%)
 * Likes:    30
 * Dislikes: 0
 * Total Accepted:    9K
 * Total Submissions: 16.8K
 * Testcase Example:  '[2,3,4,6]'
 *
 * 给你一个由 不同 正整数组成的数组 nums ，请你返回满足 a * b = c * d 的元组 (a, b, c, d) 的数量。其中 a、b、c 和
 * d 都是 nums 中的元素，且 a != b != c != d 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,4,6]
 * 输出：8
 * 解释：存在 8 个满足题意的元组：
 * (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
 * (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,4,5,10]
 * 输出：16
 * 解释：存在 16 个满足题意的元组：
 * (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
 * (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
 * (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
 * (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 10^4
 * nums 中的所有元素 互不相同
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let mut map = std::collections::HashMap::new();
        let mut res = 0;
        for i in 0..nums.len() {
            for j in i+1..nums.len() {
                let product = nums[i] * nums[j];
                *map.entry(product).or_insert(0) += 1;
            }
        }
        for (_k, v) in map {
            res += v * (v - 1) / 2 * 8;
        }
        res
    }
}
// @lc code=end

