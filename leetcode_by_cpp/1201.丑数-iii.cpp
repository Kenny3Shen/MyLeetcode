/*
 * @lc app=leetcode.cn id=1201 lang=cpp
 *
 * [1201] 丑数 III
 *
 * https://leetcode-cn.com/problems/ugly-number-iii/description/
 *
 * algorithms
 * Medium (24.25%)
 * Likes:    63
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 18.7K
 * Testcase Example:  '3\n2\n3\n5'
 *
 * 请你帮忙设计一个程序，用来找出第 n 个丑数。
 * 
 * 丑数是可以被 a 或 b 或 c 整除的 正整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 3, a = 2, b = 3, c = 5
 * 输出：4
 * 解释：丑数序列为 2, 3, 4, 5, 6, 8, 9, 10... 其中第 3 个是 4。
 * 
 * 示例 2：
 * 
 * 输入：n = 4, a = 2, b = 3, c = 4
 * 输出：6
 * 解释：丑数序列为 2, 3, 4, 6, 8, 9, 10, 12... 其中第 4 个是 6。
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 5, a = 2, b = 11, c = 13
 * 输出：10
 * 解释：丑数序列为 2, 4, 6, 8, 10, 11, 12, 13... 其中第 5 个是 10。
 * 
 * 
 * 示例 4：
 * 
 * 输入：n = 1000000000, a = 2, b = 217983653, c = 336916467
 * 输出：1999999984
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n, a, b, c <= 10^9
 * 1 <= a * b * c <= 10^18
 * 本题结果在 [1, 2 * 10^9] 的范围内
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        if (n == 1)
            return min(a, min(b, c));
        vector<int> dp(n + 1);
        int ta = 0, tb = 0, tc = 0;
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = min(dp[ta] * a, min(dp[tb] * b, dp[tc] * c));
            ta += dp[i] == dp[ta] * a;
            tb += dp[i] == dp[tb] * b;
            tc += dp[i] == dp[tc] * c;
        }
        return dp[n];
    }
};
// @lc code=end
