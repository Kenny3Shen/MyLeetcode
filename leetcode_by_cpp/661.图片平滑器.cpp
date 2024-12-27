/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 *
 * https://leetcode-cn.com/problems/image-smoother/description/
 *
 * algorithms
 * Easy (55.13%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    13K
 * Total Submissions: 23.6K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入)
 * ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * 输出:
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 * 解释:
 * 对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
 * 对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
 * 对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
 * 
 * 
 * 注意:
 * 
 * 
 * 给定矩阵中的整数范围为 [0, 255]。
 * 矩阵的长和宽的范围均为 [1, 150]。
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    const int dx[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
    const int dy[9] = {0, 1, 0, -1, -1, -1, 0, 1, 1};
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        int row = M.size();
        int col = M[0].size();
        vector<vector<int>> res(M);
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                int sum = 0, cur = 0;
                for (int t = 0; t < 9; ++t)
                {
                    int x = i + dx[t];
                    int y = j + dy[t];
                    if (x < row && y < col && x >= 0 && y >= 0)
                    {
                        sum += M[x][y];
                        cur++;
                    }
                }
                res[i][j] = sum / cur;
            }
        }
        return res;
    }
};
// @lc code=end
