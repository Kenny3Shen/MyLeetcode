/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 *
 * https://leetcode-cn.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (39.01%)
 * Likes:    406
 * Dislikes: 0
 * Total Accepted:    34.5K
 * Total Submissions: 85.6K
 * Testcase Example:  '"1 + 1"'
 *
 * 实现一个基本的计算器来计算一个简单的字符串表达式 s 的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "1 + 1"
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = " 2-1 + 2 "
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(1+(4+5+2)-3)+(6+8)"
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
 * s 表示一个有效的表达式
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        int res = 0, sign = 1, num = 0;
        stack<int> st;
        for (char &c : s)
        {
            if (c == ' ')
                continue;
            else if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (c == '+' || c == '-')
            {
                res += sign * num;
                num = 0;
                sign = c == '+' ? 1 : -1;
            }
            else if (c == '(')
            {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')')
            {
                res += sign * num;
                num = 0;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        res += sign * num;
        return res;
    }
};
/* 
res 表示左边表达式除去栈内保存元素的计算结果；
sign 表示运算符；
num 表示当前遇到的数字，会更新到 res 中；
用栈保存遇到左括号时前面计算好了的结果和运算符。
操作的步骤是：

如果当前是数字，那么更新计算当前数字；
如果当前是操作符+或者-，那么需要更新计算当前计算的结果 res，并把当前数字 num 设为 0，sign 设为正负，重新开始；
如果当前是 ( ，那么说明遇到了右边的表达式，而后面的小括号里的内容需要优先计算，所以要把 res，sign 进栈，更新 res 和 sign 为新的开始；
如果当前是 ) ，那么说明右边的表达式结束，即当前括号里的内容已经计算完毕，所以要把之前的结果出栈，然后计算整个式子的结果；
最后，当所有数字结束的时候，需要把最后的一个 num 也更新到 res 中。 */

// @lc code=end
