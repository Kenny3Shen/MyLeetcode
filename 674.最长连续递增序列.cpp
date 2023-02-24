/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 *
 * https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/description/
 *
 * algorithms
 * Easy (45.57%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    53.2K
 * Total Submissions: 114.1K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。
 * 
 * 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l ，都有 nums[i] < nums[i + 1] ，那么子序列
 * [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,5,4,7]
 * 输出：3
 * 解释：最长连续递增序列是 [1,3,5], 长度为3。
 * 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,2,2,2]
 * 输出：1
 * 解释：最长连续递增序列是 [2], 长度为1。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        /* //dynamic programming
        if (nums.empty())
            return 0;
        int res = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] > nums[i])
                dp[i + 1] = dp[i] + 1;
            res = max(dp[i + 1], res);
        }
        return res; */

        if (nums.size() < 2)
            return nums.size();
        int res = 1;
        int cur = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i + 1] > nums[i])
                cur++;
            else
                cur = 1;
            res = max(cur, res);
        }
        return res;
        /* vector<int> st;
        int res = 0;
        nums.push_back(INT32_MIN);
        for (int i = 0; i < nums.size(); i++)
        {
            if (st.empty())
            {
                st.push_back(nums[i]);
                continue;
            }
            if (st.back() >= nums[i])
            {
                if (st.size() > res)
                    res = st.size();
                st.clear();
                st.push_back(nums[i]);
            }
            else
                st.push_back(nums[i]);
        }
        return res; */
    }
};
// @lc code=end
