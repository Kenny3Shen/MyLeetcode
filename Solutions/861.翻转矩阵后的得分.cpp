/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int matrixScore(vector<vector<int>> &A)
    {
        if (A.empty())
            return 0;
        int res = 0;
        int row = A.size(), col = A[0].size();
        // 逐行判断，将首位为0的行进行翻转操作
        for (int i = 0; i < row; ++i)
        {
            if (A[i][0] == 0)
            {
                for (int j = 0; j < col; ++j)
                {
                    // 进行翻转操作
                    A[i][j] = (1 - A[i][j]);
                }
            }
        }
        // 从第二列开始逐列判断是否需进行翻转操作，在判断是否
        // 需要进行行翻转操作时，保证了第一列必全为1
        for (int j = 1; j < col; ++j)
        {
            // 设置变量统计该行0的个数
            int cnt = 0;
            for (int i = 0; i < row; ++i)
            {
                if (A[i][j] == 0)
                {
                    ++cnt;
                }
            }
            // 若该列中0个数多余1个数，做列翻转操作
            if (cnt > (row - cnt))
            {
                for (int i = 0; i < row; ++i)
                {
                    A[i][j] = (1 - A[i][j]);
                }
            }
        }
        // 得最后二进制结果
        for (int i = 0; i < row; ++i)
        {
            for (int j = col - 1; j >= 0; --j)
            {
                res += A[i][j] * int(pow(2, col - 1 - j));
            }
        }
        return res;
    }
};
// @lc code=end
