/*
 * @lc app=leetcode.cn id=2574 lang=cpp
 *
 * [2574] 左右元素和的差值
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    vector<int> leftRigthDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        int leftSum = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < n; i++)
        {
            res[i] = abs((sum - nums[i] - leftSum) - leftSum);
            leftSum += nums[i];
        }
        return res;
    }
};
// @lc code=end
