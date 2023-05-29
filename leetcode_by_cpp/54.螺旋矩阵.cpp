/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (42.58%)
 * Likes:    609
 * Dislikes: 0
 * Total Accepted:    103K
 * Total Submissions: 241.2K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        if (row == 0)
            return {};
        int top = 0, buttom = row - 1, left = 0, right = col - 1;
        vector<int> res(row * col);
        int index = 0;
        while (1)
        {
            for (int i = left; i <= right; i++)
                res[index++] = matrix[top][i];
            top++;
            if (top > buttom)
                break;

            for (int i = top; i <= buttom; i++)
                res[index++] = matrix[i][right];
            right--;
            if (left > right)
                break;

            for (int i = right; i >= left; i--)
                res[index++] = matrix[buttom][i];
            buttom--;
            if (top > buttom)
                break;

            for (int i = buttom; i >= top; i--)
                res[index++] = matrix[i][left];
            left++;
            if (left > right)
                break;
        }
        return res;

        /* if(matrix.empty())
            return {};
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res(row * col);
        int loop = min(col / 2, row / 2);
        int mid = loop;
        int offset = 1;
        int index = 0;
        int startX = 0, startY = 0;
        int i, j;
        while(loop--)
        {
            i = startX;
            j = startY;
            for(j = startY; j < startY + col - offset; j++)
                res[index++] = matrix[startX][j];
            
            for(i = startX; i < startX + row - offset; i++)
                res[index++] = matrix[i][j];

            for(; j > startY; j--)
                res[index++] = matrix[i][j];
            
            for(; i > startX; i--)
                res[index++] = matrix[i][j];

            startX++;
            startY++;
            offset += 2;
        }

        if(col == row && col % 2)
            res[index] = matrix[mid][mid];
        else if(row % 2 && col > row)
            for(int k = mid; k < col - (offset / 2); k++)
                res[index++] = matrix[mid][k];
        else if(col % 2 && row > col)
            for(int k = mid; k < row - (offset / 2); k++)
                res[index++] = matrix[k][mid];
        return res; */
    }
};
// @lc code=end
