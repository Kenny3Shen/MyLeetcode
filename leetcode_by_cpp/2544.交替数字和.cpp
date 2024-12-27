/*
 * @lc app=leetcode.cn id=2544 lang=cpp
 *
 * [2544] 交替数字和
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int alternateDigitSum(int n)
    {
        stack<int> st;
        while (n)
        {
            st.push(n % 10);
            n /= 10;
        }
        int res = 0;
        int sign = 1;
        while (!st.empty())
        {
            res += sign * st.top();
            st.pop();
            sign *= -1;
        }
        return res;
    }
};
// @lc code=end
