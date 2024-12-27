/*
 * @lc app=leetcode.cn id=2373 lang=cpp
 *
 * [2373] 矩阵中的局部最大值
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        for (int i = 0; i < n - 2; i++)
            for (int j = 0; j < n - 2; j++)
                for (int k = i; k < i + 3; k++)
                    for (int z = j; z < j + 3; z++)
                        res[i][j] = max(res[i][j], grid[k][z]);
        return res;
    }
};
// @lc code=end
