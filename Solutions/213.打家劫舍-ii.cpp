/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (39.26%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    51.1K
 * Total Submissions: 130.2K
 * Testcase Example:  '[2,3,2]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,2]
 * 输出: 3
 * 解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        
        /* nt n = nums.size();
        if (n == 0)
            return 0;
        else if (n < 4)
            return (*max_element(nums.begin(), nums.end()));
        
        int dp[n][2];       //边界情况：
        dp[0][0] = 0;       //没偷第0家时，偷到前0家的最大金额为0
        dp[0][1] = nums[0]; //有偷第0家时，偷到前0家的最大金额为nums[0]
        dp[1][0] = nums[1]; //没偷第0家时，偷到前1家的最大金额为nums[1]
        dp[1][1] = nums[0]; //有偷第0家时，偷到前1家的最大金额为nums[0]
        for (int i = 2; i < n; i++)
        {
            if (i != n - 1)
            {
                //如果不是偷最后一家，分有偷第0家和不偷第0家两条路线进行状态转移
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + nums[i]);
            }
            else
            {
                //偷最后一家时,如果没偷过第0家，可以直接选择偷或者不偷
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i]);
                //如果已经偷过第0家，只能选择不偷
                dp[i][1] = dp[i - 1][1];
            }
        }
        //返回两种偷法中金额较大的一种
        return max(dp[n - 1][0], dp[n - 1][1]); */
    }
};
//第一间房子和最后一间房子定义为相邻的房子，所以我们在求解最后一间房子即dp[n - 1]时还要考虑是否有偷第一间房子的情况
// @lc code=end
