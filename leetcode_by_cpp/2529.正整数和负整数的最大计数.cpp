/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int pos = 0, neg = 0;
        for (int n : nums)
        {
            if (n > 0)
                pos++;
            else if (n < 0)
                neg++;
        }
        return max(pos, neg);
    }
};
// @lc code=end
