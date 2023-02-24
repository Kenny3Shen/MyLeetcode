/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        /* int result = 0;
        int minPrice = prices[0]; // 记录最低价格
        for (int i = 1; i < prices.size(); i++)
        {
            // 买入
            if (prices[i] < minPrice)
                minPrice = prices[i]; // 情况二

            // 计算利润，可能有多次计算利润，最后一次计算利润才是真正意义的卖出
            if (prices[i] > minPrice + fee)
            {
                result += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee; // 情况一，这一步很关键
            }
        }
        return result; */

        // dp[i][1]第i天持有的最多现金
        // dp[i][0]第i天持有股票所剩的最多现金
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] -= prices[0]; // 持股票
        for (int i = 1; i < n; i++)
        {
            // 第i天持股票所剩最多现金 = max(第i-1天持股票所剩现金, 第i-1天持现金-买第i天的股票)
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // 第i天持有最多现金 = max(第i-1天持有的最多现金，第i-1天持有股票所剩的最多现金+第i天卖出股票-手续费)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);

        /* 定义状态转移方程：
        不持有：dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee)
        dp[i][0]=max(dp[i−1][0],dp[i−1][1]+prices[i]−fee)
        对于今天不持有，可以从两个状态转移过来：1. 昨天也不持有；2. 昨天持有，今天卖出。两者取较大值。
        
        持有：dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])
        dp[i][1]=max(dp[i−1][1],dp[i−1][0]−prices[i])
        对于今天持有，可以从两个状态转移过来：1. 昨天也持有；2. 昨天不持有，今天买入。两者取较大值。
         */
    }
};
//因为如果还在收获利润的区间里，表示并不是真正的卖出，而计算利润每次都要减去手续费，
//所以要让minPrice = prices[i] - fee;，这样在明天收获利润的时候，才不会多减一次手续费！

// @lc code=end
