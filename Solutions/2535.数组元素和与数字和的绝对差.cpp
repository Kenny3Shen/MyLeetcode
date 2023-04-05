/*
 * @lc app=leetcode.cn id=2535 lang=cpp
 *
 * [2535] 数组元素和与数字和的绝对差
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {
        int sum1 = accumulate(nums.begin(), nums.end(), 0);
        int sum2 = 0;
        for (int n : nums)
        {
            while (n)
            {
                sum2 += n % 10;
                n /= 10;
            }
        }
        return abs(sum1 - sum2);
    }
};
// @lc code=end
