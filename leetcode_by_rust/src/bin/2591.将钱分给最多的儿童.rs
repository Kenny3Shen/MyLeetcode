/*
 * @lc app=leetcode.cn id=2591 lang=rust
 *
 * [2591] 将钱分给最多的儿童
 *
 * https://leetcode.cn/problems/distribute-money-to-maximum-children/description/
 *
 * algorithms
 * Easy (21.05%)
 * Likes:    24
 * Dislikes: 0
 * Total Accepted:    6.8K
 * Total Submissions: 31.8K
 * Testcase Example:  '20\n3'
 *
 * 给你一个整数 money ，表示你总共有的钱数（单位为美元）和另一个整数 children ，表示你要将钱分配给多少个儿童。
 *
 * 你需要按照如下规则分配：
 *
 *
 * 所有的钱都必须被分配。
 * 每个儿童至少获得 1 美元。
 * 没有人获得 4 美元。
 *
 *
 * 请你按照上述规则分配金钱，并返回 最多 有多少个儿童获得 恰好 8 美元。如果没有任何分配方案，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：money = 20, children = 3
 * 输出：1
 * 解释：
 * 最多获得 8 美元的儿童数为 1 。一种分配方案为：
 * - 给第一个儿童分配 8 美元。
 * - 给第二个儿童分配 9 美元。
 * - 给第三个儿童分配 3 美元。
 * 没有分配方案能让获得 8 美元的儿童数超过 1 。
 *
 *
 * 示例 2：
 *
 * 输入：money = 16, children = 2
 * 输出：2
 * 解释：每个儿童都可以获得 8 美元。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= money <= 200
 * 2 <= children <= 30
 *
 *
 */

// @lc code=start
impl Solution {
    pub fn dist_money(mut money: i32, mut children: i32) -> i32 {
        if money < children {
            return -1;
        }
        money -= children; // 保证每个人至少有 1 块钱
        let mut res = std::cmp::min(children, money / 7); // 保证每个人最多有 8 块钱
        money -= res * 7;
        children -= res;
        if ((children == 0 && money > 0) || (children == 1 && money == 3)) {
            res -= 1;
        }
        res
    }
}
// @lc code=end
