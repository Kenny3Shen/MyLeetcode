/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (62.39%)
 * Likes:    332
 * Dislikes: 0
 * Total Accepted:    47.6K
 * Total Submissions: 74.4K
 * Testcase Example:  '"abc"'
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 输入："aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的字符串长度不会超过 1000 。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int countSubstrings(string s)
    {
        int result = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i) //对于每一个字母，以他为中心
        {
            int l = i, r = i;         //以s[i]作为奇回文数中心
            while (l >= 0 && r < len) //奇回文数处理
            {
                if (s[l--] == s[r++])
                    result++;
                else
                    break;
            }
            if (i < len - 1 && s[i + 1] == s[i]) //偶回文数处理
            {
                l = i, r = i + 1; //以s[i]s[i+1]作为偶回文数中心
                while (l >= 0 && r < len)
                {
                    if (s[l--] == s[r++])
                        result++;
                    else
                        break;
                }
            }
        }
        return result;
    }
};
// @lc code=end
