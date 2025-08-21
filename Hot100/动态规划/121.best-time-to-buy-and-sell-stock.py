#
# @lc app=leetcode.cn id=121 lang=python3
# @lcpr version=30204
#
# [121] 买卖股票的最佳时机
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 贪心
        n = len(prices)
        dp = [[0] * 2 for _ in range(n + 1)]
        dp[0][1] = -inf
        for i in range(n):
            # 第i天不持有股票 = max(前一天不持有股票，前一天持有股票+今天卖出)
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i])
            # 第i天持有股票 = max(前一天持有股票，-今天买入)
            dp[i + 1][1] = max(dp[i][1], -prices[i])
        return dp[n][0]
        # ans = 0
        # min_price = prices[0]
        # for i in range(1, n):
        #     ans = max(ans, prices[i] - min_price)
        #     min_price = min(min_price, prices[i])
        # return ans
# @lc code=end



#
# @lcpr case=start
# [7,1,5,3,6,4]\n
# @lcpr case=end

# @lcpr case=start
# [7,6,4,3,1]\n
# @lcpr case=end

#

