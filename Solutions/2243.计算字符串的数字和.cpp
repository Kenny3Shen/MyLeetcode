/*
 * @lc app=leetcode.cn id=2243 lang=cpp
 *
 * [2243] 计算字符串的数字和
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    string digitSum(string s, int k)
    {
        while (s.size() > k)
        {
            string t;
            int n = s.size();
            for (int i = 0; i < n; i += k)
            {
                int val = 0;
                for (int j = i; j < min(i + k, n); j++)
                    val += s[j] - '0';
                t.append(to_string(val));
            }
            s = t;
        }
        return s;
    }
};
// @lc code=end
