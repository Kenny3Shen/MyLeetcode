/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode.cn/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (45.96%)
 * Likes:    865
 * Dislikes: 0
 * Total Accepted:    198.6K
 * Total Submissions: 431.9K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X'
 * 填充。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * 输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * 解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 *
 *
 * 示例 2：
 *
 *
 * 输入：board = [["X"]]
 * 输出：[["X"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * m == board.length
 * n == board[i].length
 * 1
 * board[i][j] 为 'X' 或 'O'
 *
 *
 *
 *
 */
// dfs将地图边界相连的'O'全部改成'A'
//遍历地图将包围的'O'全部改成'X'，'A'改为'O'

#include "leetcode.h"
// @lc code=start
class Solution
{
private:
    int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1}; // 保存四个方向
    void dfs(vector<vector<char>> &board, int x, int y)
    {
        board[x][y] = 'A';
        for (int i = 0; i < 4; i++)
        { // 向四个方向遍历
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            // 超过边界
            if (nextx < 0 || nextx == board.size() || nexty < 0 || nexty == board[0].size())
                continue;
            // 不符合条件，不继续遍历
            if (board[nextx][nexty] == 'X' || board[nextx][nexty] == 'A')
                continue;
            dfs(board, nextx, nexty);
        }
        return;
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        // 步骤一：
        // 从左侧边，和右侧边 向中间遍历
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][m - 1] == 'O')
                dfs(board, i, m - 1);
        }

        // 从上边和下边 向中间遍历
        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[n - 1][j] == 'O')
                dfs(board, n - 1, j);
        }
        // 步骤二：
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }
    }
};

// @lc code=end
