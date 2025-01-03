/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (19.67%)
 * Likes:    394
 * Dislikes: 0
 * Total Accepted:    57.6K
 * Total Submissions: 287.2K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) =
 * -2
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 解释: 7/-3 = truncate(-2.33333..) = -2
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if(dividend == 0)
            return 0;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int dividendSign = dividend >> 31;
        int divisorSign = divisor >> 31;
        int minus = divisorSign ^ dividendSign;
        long long res = 0;
        long long plus = 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        while (plus <= dividend)
        {
            plus += divisor;
            res++;
        }
        return minus ? -(res - 1) : res - 1;
    }
};
// dividend = divisor * res = divisor + ... + divisor
// @lc code=end
