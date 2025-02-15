/*
 * @lc app=leetcode.cn id=1222 lang=rust
 *
 * [1222] 可以攻击国王的皇后
 *
 * https://leetcode.cn/problems/queens-that-can-attack-the-king/description/
 *
 * algorithms
 * Medium (69.60%)
 * Likes:    59
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 14.1K
 * Testcase Example:  '[[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]]\n[0,0]'
 *
 * 在一个 8x8 的棋盘上，放置着若干「黑皇后」和一个「白国王」。
 *
 * 给定一个由整数坐标组成的数组 queens ，表示黑皇后的位置；以及一对坐标 king
 * ，表示白国王的位置，返回所有可以攻击国王的皇后的坐标(任意顺序)。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
 * 输出：[[0,1],[1,0],[3,3]]
 * 解释：
 * [0,1] 的皇后可以攻击到国王，因为他们在同一行上。
 * [1,0] 的皇后可以攻击到国王，因为他们在同一列上。
 * [3,3] 的皇后可以攻击到国王，因为他们在同一条对角线上。
 * [0,4] 的皇后无法攻击到国王，因为她被位于 [0,1] 的皇后挡住了。
 * [4,0] 的皇后无法攻击到国王，因为她被位于 [1,0] 的皇后挡住了。
 * [2,4] 的皇后无法攻击到国王，因为她和国王不在同一行/列/对角线上。
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
 * 输出：[[2,2],[3,4],[4,4]]
 *
 *
 * 示例 3：
 *
 *
 *
 *
 * 输入：queens =
 * [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]],
 * king = [3,4]
 * 输出：[[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= queens.length <= 63
 * queens[i].length == 2
 * 0 <= queens[i][j] < 8
 * king.length == 2
 * 0 <= king[0], king[1] < 8
 * 一个棋盘格上最多只能放置一枚棋子。
 *
 *
 */

// @lc code=start
impl Solution {
    pub fn queens_attackthe_king(queens: Vec<Vec<i32>>, king: Vec<i32>) -> Vec<Vec<i32>> {
        const DIR: [(i32, i32); 8] = [
            (-1, 0),
            (-1, 1),
            (-1, -1),
            (0, 1),
            (0, -1),
            (1, 1),
            (1, 0),
            (1, -1),
        ];
        let mut res = vec![];
        let mut chess = vec![vec![false; 8]; 8];
        for q in queens {
            chess[q[0] as usize][q[1] as usize] = true;
        }
        for (x, y) in DIR {
            let (mut row, mut col) = (king[0], king[1]);
            while row + x >= 0 && row + x < 8 && col + y >= 0 && col + y < 8 {
                row += x;
                col += y;
                if chess[row as usize][col as usize] {
                    res.push(vec![row, col]);
                    break;
                }
            }
        }
        res
    }
}
// @lc code=end
