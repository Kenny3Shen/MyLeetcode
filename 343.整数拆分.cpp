/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (58.62%)
 * Likes:    358
 * Dislikes: 0
 * Total Accepted:    59.1K
 * Total Submissions: 100.7K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int integerBreak(int n)
    {
        // n >= 2
        /* if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> dp(n + 1, 0); //显然 n>3 时，2,3 拆分会使值更小
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++)
            for (int j = 2; j <= i / 2; j++)           //可证划分 1 时结果必定更小
                dp[i] = max(dp[j] * dp[i - j], dp[i]); //状态转移方程
        return dp[n]; */

        {
            vector<int> dp(n + 1, 0);
            dp[2] = 1;
            for(int i = 3; i <= n; i++)
            {
                for(int j = 1; j < i - 1; j++)
                {
                    dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
                }
            }
            return dp[n];
        }
    } 
};
// @lc code=end
