/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (46.41%)
 * Likes:    1021
 * Dislikes: 0
 * Total Accepted:    171.8K
 * Total Submissions: 369.8K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,1]
 * 输出：4
 * 解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2：
 * 
 * 输入：[2,7,9,3,1]
 * 输出：12
 * 解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 100
 * 0 <= nums[i] <= 400
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        /* int n = nums.size();
        if (n == 0)
            return 0;
        if (n < 3)
            return *max_element(nums.begin(), nums.end());
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int k = 2; k <= n; k++)
        {   //分隔成是否偷最后一间房子
            //不偷，则求前 n-1 个房子的值
            //偷，则求前 n-2 个房子 + 最后一个房子的值
            dp[k] = max(dp[k - 1], nums[k - 1] + dp[k - 2]);
        }
        return dp[n]; */
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        //vector<int> dp(n, 0);
        //dp[0] = nums[0];
        //dp[1] = max(nums[0], nums[1]);
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        int res = 0;
        for (int i = 2; i < n; i++)
        {
            res = max(first + nums[i], second);
            first = second;
            second = res;
            //dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return res;
        //return dp.back();
    }
};
// @lc code=end
