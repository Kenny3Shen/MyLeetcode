#
# @lc app=leetcode.cn id=188 lang=python3
# @lcpr version=30204
#
# [188] 买卖股票的最佳时机 IV
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        dp = [[[0] * 2 for _ in range(k + 1)] for _ in range(n + 1)]
        # 第0天不持有股票
        for i in range(k + 1):
            dp[0][i][1] = -inf
        for i in range(n):
            for j in range(k, 0, -1):
                # 第i天不持有股票 = max(前一天不持有股票，前一天持有股票+今天卖出)
                # 卖出只是完成了已经开始的交易，而不是新开始一笔交易
                dp[i + 1][j][0] = max(dp[i][j][0], dp[i][j][1] + prices[i])
                # 第i天持有股票 = max(前一天持有股票，前一天不持有股票-今天买入, 交易次数-1)
                # 买入表示开始了一笔新交易，而不是完成了已经开始的交易，因此交易次数-1
                dp[i + 1][j][1] = max(dp[i][j][1], dp[i][j - 1][0] - prices[i])

        return dp[n][k][0]


# @lc code=end


#
# @lcpr case=start
# 2\n[2,4,1]\n
# @lcpr case=end

# @lcpr case=start
# 2\n[3,2,6,5,0,3]\n
# @lcpr case=end

#
