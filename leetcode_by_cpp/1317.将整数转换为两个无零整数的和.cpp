/*
 * @lc app=leetcode.cn id=1317 lang=cpp
 *
 * [1317] 将整数转换为两个无零整数的和
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        for (int a = 1; a < n; a++)
        {
            int b = n - a;
            if (to_string(a).find('0') == string::npos && to_string(b).find('0') == string::npos)
                return {a, b};
        }
        return {0, 0};
    }
};
// @lc code=end
