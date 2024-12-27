/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (78.37%)
 * Likes:    263
 * Dislikes: 0
 * Total Accepted:    52.4K
 * Total Submissions: 66.8K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        //左闭右开，统一边界处理
        vector<vector<int>> martix(n, vector<int>(n, 0));
        int loop = n >> 1;          //对最外围填充的轮数
        int startX = 0, startY = 0; //对未处理最外围的起始位置
        int border = n - 1;         //每一次对对未处理最外围循环次数
        int count = 1;
        while (loop--)
        {
            int i = startX;
            int j = startY;

            while (j < border)
                martix[i][j++] = count++;
            while (i < border)
                martix[i++][j] = count++;
            while (j > startY)
                martix[i][j--] = count++;
            while (i > startX)
                martix[i--][j] = count++;
            
            startX++;
            startY++;
            border--;
        }
        if (n & 1)
            martix[n >> 1][n >> 1] = n * n; //n 是奇数是单独对中点处理
        return martix;
    }
};
// @lc code=end
