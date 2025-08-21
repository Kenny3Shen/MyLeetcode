#
# @lc app=leetcode.cn id=309 lang=python3
# @lcpr version=30204
#
# [309] 买卖股票的最佳时机含冷冻期
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[0] * 2 for _ in range(n + 1)]
        # 第0天不持有股票
        dp[0][1] = -inf
        for i in range(n):
            # 第i天不持有股票 = max(前一天不持有股票，前一天持有股票+今天卖出)
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + prices[i])
            # 第i天持有股票 = max(前一天持有股票，前1+1天不持有股票-今天买入)
            dp[i + 1][1] = max(dp[i][1], dp[i - 1][0] - prices[i])
        return dp[n][0]
# @lc code=end



#
# @lcpr case=start
# [1,2,3,0,2]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

