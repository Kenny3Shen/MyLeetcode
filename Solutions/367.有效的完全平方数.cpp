/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (43.35%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    40.9K
 * Total Submissions: 94.2K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        /* if (num == 0 || num == 1)
            return true;
        int left = 0, right = num;
        while (left < right)
        {
            unsigned long long mid = left + (right - left) / 2;
            unsigned long long mid2 = mid * mid;
            if (mid2 > num)
                right = mid;
            else if (mid2 < num)
                left = mid + 1;
            else
                return true;
        }
        return false; */

        //完全平方数 n^2 = 1 + 3 + ... + (2n - 1) 
            //          = (1 + 2n - 1)* n / 2
        int odd = 1;
        while (num > 0){
            num -= odd;
            odd += 2;
        }
        return num == 0;

    }
};
// @lc code=end
