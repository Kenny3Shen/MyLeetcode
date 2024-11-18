/*
 * @lc app=leetcode.cn id=3274 lang=rust
 * @lcpr version=30204
 *
 * [3274] 检查棋盘方格颜色是否相同
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn check_two_chessboards(coordinate1: String, coordinate2: String) -> bool {
        let c1 = coordinate1.as_bytes();
        let c2 = coordinate2.as_bytes();
        let t1 = (c1[0] - b'a') + (c1[1] - b'1');
        let t2 = (c2[0] - b'a') + (c2[1] - b'1');
        t1 % 2 == t2 % 2
    }
}
// @lc code=end



/*
// @lcpr case=start
// "a1"\n"c3"\n
// @lcpr case=end

// @lcpr case=start
// "a1"\n"h3"\n
// @lcpr case=end

 */

