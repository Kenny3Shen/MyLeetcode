/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        int re = 0;
        int miss = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                re = nums[i];
                break;
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += i;
        miss = sum - accumulate(nums.begin(), nums.end(), 0) + re;
        return {re, miss};
    }
};
// @lc code=end
