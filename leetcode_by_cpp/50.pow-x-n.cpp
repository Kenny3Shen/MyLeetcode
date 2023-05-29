/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.cn/problems/powx-n/description/
 *
 * algorithms
 * Medium (37.99%)
 * Likes:    1037
 * Dislikes: 0
 * Total Accepted:    323.1K
 * Total Submissions: 850.4K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，x^n^ ）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：x = 2.00000, n = 10
 * 输出：1024.00000
 *
 *
 * 示例 2：
 *
 *
 * 输入：x = 2.10000, n = 3
 * 输出：9.26100
 *
 *
 * 示例 3：
 *
 *
 * 输入：x = 2.00000, n = -2
 * 输出：0.25000
 * 解释：2^-2 = 1/2^2 = 1/4 = 0.25
 *
 *
 *
 *
 * 提示：
 *
 *
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * -10^4 <= x^n <= 10^4
 *
 *
 */
#include "leetcode.h"
// n = 2^0 b0 + 2^1 b1 + ....
// x = x^n = x ^ (2^0 b0 + 2^1 b1 + ....) = (x ^ 2^0 b0)(x ^ 2^1 b1) ...
//   = x^1b0 x^2b1 x^4b2
// x^2^nbn = bn ? x^2^n : 1 
// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0.0)
            return 0.0;
        long b = n;
        if (b < 0)
            x = 1 / x, b = -b;
        double res = 1.0; // 2^0
        while (b)
        {
            if (b & 1)
                res *= x;
            else
                res *= 1;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};
// @lc code=end
