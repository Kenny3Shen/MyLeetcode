/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 *
 * https://leetcode-cn.com/problems/basic-calculator-ii/description/
 *
 * algorithms
 * Medium (38.94%)
 * Likes:    322
 * Dislikes: 0
 * Total Accepted:    50.6K
 * Total Submissions: 119.8K
 * Testcase Example:  '"3+2*2"'
 *
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
 * 
 * 整数除法仅保留整数部分。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "3+2*2"
 * 输出：7
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = " 3/2 "
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = " 3+5 / 2 "
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
 * s 表示一个 有效表达式
 * 表达式中的所有整数都是非负整数，且在范围 [0, 2^31 - 1] 内
 * 题目数据保证答案是一个 32-bit 整数
 * 
 * 
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
        char preOperater = '+';
        int num = 0;
        vector<int> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1)
            {
                if (preOperater == '+')
                    st.push_back(num);
                else if (preOperater == '-')
                    st.push_back(-num);
                else if (preOperater == '*')
                {
                    int preNum = st.back();
                    st.pop_back();
                    st.push_back(preNum * num);
                }
                else if (preOperater == '/')
                {
                    int preNum = st.back();
                    st.pop_back();
                    st.push_back(preNum / num);
                }
                preOperater = s[i];
                num = 0;
            }
        }
        // 先乘除， 泛化为一个只有 + 运算符的表达式
        return accumulate(st.begin(), st.end(), 0);
    }
};
// @lc code=end
