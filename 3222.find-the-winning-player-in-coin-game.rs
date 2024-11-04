/*
 * @lc app=leetcode.cn id=3222 lang=rust
 * @lcpr version=30204
 *
 * [3222] 求出硬币游戏的赢家
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn losing_player(mut x: i32, mut y: i32) -> String {
        let mut res = 0;
        while x >= 1 && y >= 4 {
            res += 1;
            x -= 1;
            y -= 4;
        }
        if res % 2 == 1 {
            "Alice".to_string()
        } else {
            "Bob".to_string()
        }
    }
}
// @lc code=end



/*
// @lcpr case=start
// 2\n7\n
// @lcpr case=end

// @lcpr case=start
// 4\n11\n
// @lcpr case=end

 */

