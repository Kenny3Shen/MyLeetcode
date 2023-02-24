/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.71%)
 * Likes:    1716
 * Dislikes: 0
 * Total Accepted:    180.5K
 * Total Submissions: 362.9K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
#include "leetcode.h"
// @lc code=start

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        /* int res = INT_MIN;
        int count = 0;
        for (auto &n : nums)
        {
            count += n;
            res = max(res, count);
            count = count < 0 ? 0 : count;
        }
        return res; */

        //DP
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
