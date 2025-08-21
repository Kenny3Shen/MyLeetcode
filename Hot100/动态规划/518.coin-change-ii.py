#
# @lc app=leetcode.cn id=518 lang=python3
# @lcpr version=30204
#
# [518] 零钱兑换 II
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # 假设每一种面额的硬币有无限个。完全背包问题
        n = len(coins)
        dp = [[0] * (amount + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(n):
            for j in range(amount + 1):
                if j >= coins[i]:
                    dp[i + 1][j] = dp[i][j] + dp[i + 1][j - coins[i]]
                else:
                    dp[i + 1][j] = dp[i][j]
        return dp[n][amount]
        # dp = [0] * (amount + 1)
        # dp[0] = 1
        # for i in range(n):
        #     for j in range(coins[i], amount + 1):
        #         dp[j] += dp[j - coins[i]]
        # return dp[amount]
# @lc code=end



#
# @lcpr case=start
# 5\n[1, 2, 5]\n
# @lcpr case=end

# @lcpr case=start
# 3\n[2]\n
# @lcpr case=end

# @lcpr case=start
# 10\n[10]\n
# @lcpr case=end

#

