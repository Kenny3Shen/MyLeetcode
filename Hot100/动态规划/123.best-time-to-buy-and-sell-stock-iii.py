#
# @lc app=leetcode.cn id=123 lang=python3
# @lcpr version=30204
#
# [123] 买卖股票的最佳时机 III
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # n = len(prices)
        # dp = [[0] * 2 for _ in range(3)]
        # for i in range(3):
        #     dp[i][1] = -inf
        # for i in range(n):
        #     for j in range(1, 3):
        #         # 第i天不持有股票 = max(前一天不持有股票，前一天持有股票+今天卖出)
        #         dp[j][0] = max(dp[j][0], dp[j][1] + prices[i])
        #         # 第i天持有股票 = max(前一天持有股票，前一天不持有股票-今天买入)
        #         dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i])
        # return dp[2][0]

        n = len(prices)
        dp = [[[0] * 2 for _ in range(3)] for _ in range(n + 1)]
        for i in range(3):
            dp[0][i][1] = -inf
        for i in range(n):
            for j in range(3):
                dp[i + 1][j][0] = max(dp[i][j][0], dp[i][j][1] + prices[i])
                dp[i + 1][j][1] = max(dp[i][j][1], dp[i][j - 1][0] - prices[i])
        return dp[n][2][0]


# @lc code=end


#
# @lcpr case=start
# [3,3,5,0,0,3,1,4]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,5]\n
# @lcpr case=end

# @lcpr case=start
# [7,6,4,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#
