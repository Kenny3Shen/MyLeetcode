/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (62.36%)
 * Likes:    820
 * Dislikes: 0
 * Total Accepted:    203.3K
 * Total Submissions: 325.5K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
 * 
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [7,1,5,3,6,4]
 * 输出: 7
 * 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
 * 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,4,5]
 * 输出: 4
 * 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4
 * 。
 * 注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。
 * 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,6,4,3,1]
 * 输出: 0
 * 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= prices.length <= 3 * 10 ^ 4
 * 0 <= prices[i] <= 10 ^ 4
 * 
 * 
 */

#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        //Dynamic Programming
        //0 持有股票
        //1 不持有股票
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            //dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp.back()[1];
        /*//单调递增栈 
        vector<int> min;
        int max = 0;
        min.push_back(prices[0]);
        for (int i = 1; i < prices.size(); i++)
        {
            if (min.back() > prices[i])
            {
                if (min.size() > 1)
                {
                    max += min.back() - min.front();
                    min.clear();
                    min.push_back(prices[i]);
                }
                else
                {
                    min.pop_back();
                    min.push_back(prices[i]);
                }
            }
            else
                min.push_back(prices[i]);
        }
        if (min.size() > 1)
            max += min.back() - min.front();
        return max; */

        // 贪心算法：一次遍历；逢低便买入，逢高便卖出
        // 只要前一天的价格小于后一天的价格便在前一天买入后一天卖出
        /* int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            maxProfit += max(prices[i] - prices[i - 1], 0);
        }
        return maxProfit; */
    }
};
// @lc code=end
