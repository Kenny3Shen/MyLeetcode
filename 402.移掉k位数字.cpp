/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 *
 * https://leetcode-cn.com/problems/remove-k-digits/description/
 *
 * algorithms
 * Medium (30.21%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    30K
 * Total Submissions: 99.2K
 * Testcase Example:  '"1432219"\n3'
 *
 * 给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
 * 
 * 注意:
 * 
 * 
 * num 的长度小于 10002 且 ≥ k。
 * num 不会包含任何前导零。
 * 
 * 
 * 示例 1 :
 * 
 * 
 * 输入: num = "1432219", k = 3
 * 输出: "1219"
 * 解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
 * 
 * 
 * 示例 2 :
 * 
 * 
 * 输入: num = "10200", k = 1
 * 输出: "200"
 * 解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
 * 
 * 
 * 示例 3 :
 * 
 * 
 * 输入: num = "10", k = 2
 * 输出: "0"
 * 解释: 从原数字移除所有的数字，剩余为空就是0。
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
//当所有元素都进行过栈的处理之后，如果结果stack中的元素比要保留的长度要长的话，则把栈顶元素pop掉。
//要想使移除k个元素后的数最小，则应该移除最靠左的k个相邻逆序对，包括在一次移除后形成的新的逆序对。
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.length() <= k)
            return "0";

        string st;
        for (char digit : num)
        {
            while (!st.empty() && k && st.back() > digit) //单调非递减栈，需要循环比较
            {
                st.pop_back();
                k--;
            }
            if (st.empty() && digit == '0') //在入栈的时候，可忽略掉前置0
                continue;

            st += digit;
        }
        while (k > 0 && !st.empty())
        {
            st.pop_back();
            k--;
        }
        return st == "" ? "0" : st;
    }
};
// @lc code=end
