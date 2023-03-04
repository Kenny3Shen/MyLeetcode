/*
 * @lc app=leetcode.cn id=2553 lang=cpp
 *
 * [2553] 分割数组中数字的数位
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> res;
        for (auto &n : nums)
        {
            stack<int> st;
            while (n)
            {
                st.push(n % 10);
                n /= 10;
            }
            while (!st.empty())
            {
                res.push_back(st.top());
                st.pop();
            }
        }
        return res;
    }
};
// @lc code=end
