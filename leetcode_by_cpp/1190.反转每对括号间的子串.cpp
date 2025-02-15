/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 *
 * https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
 *
 * algorithms
 * Medium (58.89%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 44.5K
 * Testcase Example:  '"(abcd)"'
 *
 * 给出一个字符串 s（仅含有小写英文字母和括号）。
 * 
 * 请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。
 * 
 * 注意，您的结果中 不应 包含任何括号。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "(abcd)"
 * 输出："dcba"
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "(u(love)i)"
 * 输出："iloveu"
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "(ed(et(oc))el)"
 * 输出："leetcode"
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "a(bcdefghijkl(mno)p)q"
 * 输出："apmnolkjihgfedcbq"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 2000
 * s 中只有小写英文字母和括号
 * 我们确保所有括号都是成对出现的
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<string> st;
        string t{};
        for(auto &c : s)
        {
            if(c == '(')
            {
                st.push(t);
                t = "";
            }
            else if(c == ')')
            {
                reverse(t.begin(), t.end());
                t = st.top() + t;
                st.pop();                
            }
            else
                t += c;
        }
        return t;
    }
};
// @lc code=end
