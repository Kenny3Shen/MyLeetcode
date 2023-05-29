/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (33.84%)
 * Likes:    1746
 * Dislikes: 0
 * Total Accepted:    299.1K
 * Total Submissions: 883.9K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        if (x / 10 == 0)
            return x; //平凡情况：若x∈[-9,9]，则直接返回其本身
        int y = 0;
        while (x)
        {
            if (y > __INT_MAX__ / 10 || y < (__INT_MAX__ + 1) / 10)
                //溢出判断，其中根据补码原理->__INT_MAX__ + 1 = INT_MIN
                return 0;
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        return y;
    }
};
// @lc code=end
