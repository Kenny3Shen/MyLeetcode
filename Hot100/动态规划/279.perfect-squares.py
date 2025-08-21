#
# @lc app=leetcode.cn id=279 lang=python3
# @lcpr version=30204
#
# [279] 完全平方数
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def numSquares(self, n: int) -> int:
        # 完全背包问题, 物品是平方数 1, 4, 9, ..., n
        # 背包容量是 n
        # dp[i] 表示凑成金额 n 所需的最少完全平方数的个数
        # 其中 dp[i] = min(dp[i], dp[i - j * j] + 1)

        dp = [0] + [inf] * n
        for i in range(1, n + 1):
            for j in range(1, int(i ** 0.5) + 1):
                dp[i] = min(dp[i], dp[i - j * j] + 1)
        return dp[n]
# @lc code=end



#
# @lcpr case=start
# 12\n
# @lcpr case=end

# @lcpr case=start
# 13\n
# @lcpr case=end

#

