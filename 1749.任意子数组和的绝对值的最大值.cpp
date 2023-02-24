/*
 * @lc app=leetcode.cn id=1749 lang=cpp
 *
 * [1749] 任意子数组和的绝对值的最大值
 *
 * https://leetcode-cn.com/problems/maximum-absolute-sum-of-any-subarray/description/
 *
 * algorithms
 * Medium (48.56%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    1.7K
 * Total Submissions: 3.5K
 * Testcase Example:  '[1,-3,2,3,-4]'
 *
 * 给你一个整数数组 nums 。一个子数组 [numsl, numsl+1, ..., numsr-1, numsr] 的 和的绝对值 为
 * abs(numsl + numsl+1 + ... + numsr-1 + numsr) 。
 * 
 * 请你找出 nums 中 和的绝对值 最大的任意子数组（可能为空），并返回该 最大值 。
 * 
 * abs(x) 定义如下：
 * 
 * 
 * 如果 x 是负整数，那么 abs(x) = -x 。
 * 如果 x 是非负整数，那么 abs(x) = x 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,-3,2,3,-4]
 * 输出：5
 * 解释：子数组 [2,3] 和的绝对值最大，为 abs(2+3) = abs(5) = 5 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,-5,1,-4,3,-2]
 * 输出：8
 * 解释：子数组 [-5,1,-4] 和的绝对值最大，为 abs(-5+1-4) = abs(-8) = 8 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        /* vector<int> preSum(nums.size() + 1, 0);
        for (int i = 1; i < nums.size() + 1; i++)
            preSum[i] = nums[i - 1] + preSum[i - 1];
        //绝对值表明，我们不关心 i <= j是否成立，若 i > j 我们取反即可
        sort(preSum.begin(), preSum.end());
        return preSum.back() - preSum[0]; */
        vector<int> s(nums.size() + 1);
        for (int i = 1; i <= nums.size(); i++)
            s[i] = s[i - 1] + nums[i - 1];
        int res = 0;
        int mx = 0, mn = 0; // mn可以取0，因为s[j]可以取到s[0]
        for (int i = 1; i <= nums.size(); i++)
        {
            mx = max(s[i], mx);
            mn = min(s[i], mn);
            res = max({res, abs(s[i] - mx), abs(s[i] - mn)});
        }
        return res;
    }
};
// @lc code=end
