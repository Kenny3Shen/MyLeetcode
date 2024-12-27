/*
 * @lc app=leetcode.cn id=3033 lang=rust
 *
 * [3033] 修改矩阵
 *
 * https://leetcode.cn/problems/modify-the-matrix/description/
 *
 * algorithms
 * Easy (78.05%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 4.1K
 * Testcase Example:  '[[1,2,-1],[4,-1,6],[7,8,9]]'
 *
 * 给你一个下标从 0 开始、大小为 m x n 的整数矩阵 matrix ，新建一个下标从 0 开始、名为 answer 的矩阵。使 answer 与
 * matrix 相等，接着将其中每个值为 -1 的元素替换为所在列的 最大 元素。
 *
 * 返回矩阵 answer 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：matrix = [[1,2,-1],[4,-1,6],[7,8,9]]
 * 输出：[[1,2,9],[4,8,6],[7,8,9]]
 * 解释：上图显示了发生替换的元素（蓝色区域）。
 * - 将单元格 [1][1] 中的值替换为列 1 中的最大值 8 。
 * - 将单元格 [0][2] 中的值替换为列 2 中的最大值 9 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：matrix = [[3,-1],[5,2]]
 * 输出：[[3,2],[5,2]]
 * 解释：上图显示了发生替换的元素（蓝色区域）。
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 2 <= m, n <= 50
 * -1 <= matrix[i][j] <= 100
 * 测试用例中生成的输入满足每列至少包含一个非负整数。
 *
 *
 */

// @lc code=start
impl Solution {
    pub fn modified_matrix(matrix: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        // 获取矩阵的行数和列数
        let m = matrix.len();
        let n = matrix[0].len();

        // 计算每一列的最大值（忽略 - 1）
        let max_col: Vec<i32> = (0..n)
            .map(|col| {
                matrix
                    .iter()
                    .map (|row| row [col]) // 获取每一行的该列的值
                    .filter (|&val| val != -1) // 忽略 - 1
                    .max () // 计算最大值
                    .unwrap_or (i32::MIN) // 如果没有非 - 1 的值，使用 i32::MIN
            })
            .collect();

        // 修改矩阵中的值
        matrix
            .into_iter()
            .map(|row| {
                row.into_iter()
                    .enumerate () // 获取每个值的列索引和值
                    .map (|(col, val)| if val == -1 { max_col [col] } else { val }) // 如果值是 - 1，用对应列的最大值替换它
                    .collect()
            })
            .collect()
    }
}
// @lc code=end
