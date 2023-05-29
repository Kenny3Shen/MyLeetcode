/*
 * @lc app=leetcode.cn id=1615 lang=cpp
 *
 * [1615] 最大网络秩
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        int res = 0;
        vector<int> degree(n);
        vector<vector<bool>> graph(n, vector<bool>(n));
        for (auto &r : roads)
        {
            degree[r[0]]++, degree[r[1]]++;
            graph[r[0]][r[1]] = graph[r[1]][r[0]] = true;
        }
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                res = max(res, degree[i] + degree[j] - graph[i][j]);
        return res;
    }
};
// @lc code=end
