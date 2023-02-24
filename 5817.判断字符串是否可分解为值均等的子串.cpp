/*
 * @lc app=leetcode.cn id=5817 lang=cpp
 *
 * [5817] 判断字符串是否可分解为值均等的子串
 *
 * https://leetcode-cn.com/problems/check-if-a-string-is-decomposble-to-value-equal-substrings/description/
 *
 * algorithms
 * Easy (57.96%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    222
 * Total Submissions: 383
 * Testcase Example:  '"000111000"'
 *
 * 一个字符串的所有字符都是一样的，被称作等值字符串。
 * 
 * 
 * 举例，"1111" 和 "33" 就是等值字符串。
 * 相比之下，"123"就不是等值字符串。
 * 
 * 
 * 规则：给出一个数字字符串s，将字符串分解成一些等值字符串，如果有且仅有一个等值子字符串长度为2，其他的等值子字符串的长度都是3.
 * 
 * 如果能够按照上面的规则分解字符串s，就返回真，否则返回假。
 * 
 * 子串就是原字符串中连续的字符序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "000111000"
 * 输出: false
 * 解释:  s只能被分解长度为3的等值子字符串。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "00011111222"
 * 输出: true
 * 解释: s 能被分解为 ["000","111","11","222"].
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "01110002223300"
 * 输出: false
 * 解释: 一个不能被分解的原因是在开头有一个0.
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅包含数字。
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    bool isDecomposable(string s)
    {
        bool flag = false;
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == s[i + 1] && s[i + 1] == s[i + 2])
                i += 3;
            else if(s[i] == s[i + 1] && s[i + 1] != s[i + 2])
            {
                if(!flag)
                {
                    flag = true;
                    i += 2;
                }
                else
                    return false;
            }
            else
                return false;
        }
        return flag;
    }
};
// @lc code=end
