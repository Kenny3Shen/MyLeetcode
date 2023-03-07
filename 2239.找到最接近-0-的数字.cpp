/*
 * @lc app=leetcode.cn id=2239 lang=cpp
 *
 * [2239] 找到最接近 0 的数字
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        int c = INT_MAX;
        for (int n : nums)
            c = min(c, abs(n));
        vector<int> t;
        for (int n : nums)
            if (abs(n) == c)
                t.push_back(n);
        return *max_element(t.begin(), t.end());
    }
};
// @lc code=end
