/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (70.82%)
 * Likes:    560
 * Dislikes: 0
 * Total Accepted:    65.6K
 * Total Submissions: 91.2K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：4
 * 输出：[
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 * 
 * 
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> vec(n, string(n, '.'));
        dfs(0, n, ans, vec);
        return ans;
    }

    void dfs(int y, int n, vector<vector<string>> &ans, vector<string> &vec)
    {
        if (y == n)
        {
            ans.push_back(vec);
        }
        else
        { 
            for (int i = 0; i < n; ++i)
            {
                vec[y][i] = 'Q';
                if (judge(vec, y, i, n))
                    dfs(y + 1, n, ans, vec);
                vec[y][i] = '.';
            }
        }
    }

    bool judge(const vector<string> &vec, int y, int x, int n)
    {
        for (int i = 0; i < y; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (vec[i][j] == 'Q' && (j == x || abs(j - x) == (y - i)))
                    return false;
            }
        }
        return true;
    }
};

// @lc code=end
