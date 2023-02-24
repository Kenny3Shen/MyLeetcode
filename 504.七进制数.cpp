/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode-cn.com/problems/base-7/description/
 *
 * algorithms
 * Easy (49.48%)
 * Likes:    55
 * Dislikes: 0
 * Total Accepted:    14.8K
 * Total Submissions: 30K
 * Testcase Example:  '100'
 *
 * 给定一个整数，将其转化为7进制，并以字符串形式输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: -7
 * 输出: "-10"
 * 
 * 
 * 注意: 输入范围是 [-1e7, 1e7] 。
 * 
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (!num)
            return "0";
        bool isMinus = false;
        string res;
        if (num >> 31)
        {
            isMinus = true;
            num = -num;
        }
        while (num)
        {
            res += (num % 7) + '0';
            num /= 7;
        }
        if (isMinus)
            res += '-';
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
