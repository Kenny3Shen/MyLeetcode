/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 *
 * https://leetcode-cn.com/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (54.28%)
 * Likes:    303
 * Dislikes: 0
 * Total Accepted:    24.3K
 * Total Submissions: 40.2K
 * Testcase Example:  '[3,4,2]'
 *
 * 给你一个整数数组 nums ，你可以对它进行一些操作。
 * 
 * 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除每个等于 nums[i] - 1 或 nums[i]
 * + 1 的元素。
 * 
 * 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,4,2]
 * 输出：6
 * 解释：
 * 删除 4 获得 4 个点数，因此 3 也被删除。
 * 之后，删除 2 获得 2 个点数。总共获得 6 个点数。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,3,3,3,4]
 * 输出：9
 * 解释：
 * 删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
 * 之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
 * 总共获得 9 个点数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int mx = 0;
        for (int n : nums)
            mx = max(mx, n);
        vector<int> dp(mx + 1), cnt(mx + 1);
        for (int n : nums)
            cnt[n]++;
        dp[1] = cnt[1];
        for (int i = 2; i <= mx; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + i * cnt[i]); //i 不选 : i 选
        return dp[mx];
        /* int cnt[10009] = {0};
        int mx = 0;
        for (auto i : nums)
        {
            cnt[i]++;
            mx = max(mx, i);
        }
        // dp[i][0] 代表「不选」数值 i
        // dp[i][1] 代表「选择」数值 i
        int dp[mx + 1][2] = {0};
        for (int i = 1; i <= mx; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + i * cnt[i];
        }
        return max(dp[mx][0], dp[mx][1]); */
    }
};
// @lc code=end
