/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (57.18%)
 * Likes:    963
 * Dislikes: 0
 * Total Accepted:    271.5K
 * Total Submissions: 474.9K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */

// @lc code=start
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x >= 0 && x < 10)
            return true; //一位数是回文
        if (x < 0 || x % 10 == 0)
            //负数、10的倍数都不为回文数
            return false;
        int bit = 0, t = x;
        while (t)
        {
            bit++; //取位数
            t /= 10;
        }
        int y = 0;
        if (bit % 2) //奇数位
        {
            for (int i = bit; i > bit / 2 + 1; i--)
            {
                y *= 10;
                y += x % 10;
                x /= 10;
            }
            return y == x / 10;
        }
        if (bit % 2 == 0) //偶数位
        {
            for (int i = bit; i > bit / 2; i--)
            {
                y *= 10;
                y += x % 10;
                x /= 10;
            }
            return y == x;
        }
        return false;
    }
};
// @lc code=end
