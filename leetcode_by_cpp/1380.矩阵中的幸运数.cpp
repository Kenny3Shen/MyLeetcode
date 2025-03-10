/*
 * @lc app=leetcode.cn id=1380 lang=cpp
 *
 * [1380] 矩阵中的幸运数
 *
 * https://leetcode-cn.com/problems/lucky-numbers-in-a-matrix/description/
 *
 * algorithms
 * Easy (72.25%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 14.9K
 * Testcase Example:  '[[3,7,8],[9,11,13],[15,16,17]]'
 *
 * 给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。
 * 
 * 幸运数是指矩阵中满足同时下列两个条件的元素：
 * 
 * 
 * 在同一行的所有元素中最小
 * 在同一列的所有元素中最大
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
 * 输出：[15]
 * 解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
 * 
 * 
 * 示例 2：
 * 
 * 输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
 * 输出：[12]
 * 解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
 * 
 * 
 * 示例 3：
 * 
 * 输入：matrix = [[7,8],[1,2]]
 * 输出：[7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= n, m <= 50
 * 1 <= matrix[i][j] <= 10^5
 * 矩阵中的所有元素都是不同的
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool judge(vector<vector<int>> &matrix, int row, int col)
    {
        int temp = matrix[row][col];
        for (int i = 0; i < matrix.size(); i++)
            if (i != row && matrix[i][col] > temp)
                return false;

        for (int i = 0; i < matrix[0].size(); i++)
            if (i != col && matrix[row][i] < temp)
                return false;
        return true;
    }
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> res;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (judge(matrix, i, j))
                {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};
// @lc code=end
