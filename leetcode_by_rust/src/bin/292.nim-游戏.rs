/*
 * @lc app=leetcode.cn id=292 lang=rust
 *
 * [292] Nim 游戏
 *
 * https://leetcode.cn/problems/nim-game/description/
 *
 * algorithms
 * Easy (70.40%)
 * Likes:    743
 * Dislikes: 0
 * Total Accepted:    178K
 * Total Submissions: 251.9K
 * Testcase Example:  '4'
 *
 * 你和你的朋友，两个人一起玩 Nim 游戏：
 * 
 * 
 * 桌子上有一堆石头。
 * 你们轮流进行自己的回合， 你作为先手 。
 * 每一回合，轮到的人拿掉 1 - 3 块石头。
 * 拿掉最后一块石头的人就是获胜者。
 * 
 * 
 * 假设你们每一步都是最优解。请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。如果可以赢，返回 true；否则，返回 false
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：false 
 * 解释：以下是可能的结果:
 * 1. 移除 1 颗石头。你的朋友移走了 3 块石头，包括最后一块。你的朋友赢了。
 * 2. 移除 2 个石子。你的朋友移走 2 块石头，包括最后一块。你的朋友赢了。
 * 3. 你移走 3 颗石子。你的朋友移走了最后一块石头。你的朋友赢了。
 * 在所有结果中，你的朋友是赢家。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 2
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn can_win_nim(n: i32) -> bool {
        (n % 4) != 0
    }
}
// @lc code=end

