/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 *
 * [1590] 使数组和能被 P 整除
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int r = accumulate(nums.begin(), nums.end(), 0LL) % p;
        if (r == 0)
            return 0;
        unordered_map<int, int> f;
        int res = nums.size();
        int preSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            f[preSum] = i;
            preSum = (preSum + nums[i]) % p;
            if (f.count((preSum - r + p) % p))
                res = min(res, i - f[(preSum - r + p) % p] + 1);
        }
        return res == nums.size() ? -1 : res;
    }
};
// @lc code=end
