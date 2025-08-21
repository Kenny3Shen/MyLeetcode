#
# @lc app=leetcode.cn id=322 lang=python3
# @lcpr version=30204
#
# [322] 零钱兑换
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[inf] * (amount + 1) for _ in range(n + 1)]
        dp[0][0] = 0
        for i in range(n):
            for j in range(amount + 1):
                if j >= coins[i]:
                    dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - coins[i]] + 1)
                else:
                    dp[i + 1][j] = dp[i][j]
        return dp[n][amount] if dp[n][amount] != inf else -1

        # dp[i] 表示凑成金额 i 所需的最少硬币个数
        n = len(coins)
        # 初始化 dp 数组，设置为无穷大表示无法凑成
        dp = [inf] * (amount + 1)
        # 金额为 0 时不需要硬币，因此为 0
        dp[0] = 0
        
        # 遍历每种硬币
        for i in range(n):
            # 对于当前硬币，计算从其面值到目标金额的每个金额所需的最少硬币数
            for j in range(coins[i], amount + 1):
                # 状态转移方程：dp[j] = min(不使用当前硬币的情况, 使用当前硬币的情况)
                dp[j] = min(dp[j], dp[j - coins[i]] + 1)
        
        # 如果最终结果是无穷大，说明无法凑成目标金额，返回 -1，否则返回所需的最少硬币数
        return dp[amount] if dp[amount] != inf else -1
# @lc code=end



#
# @lcpr case=start
# [1, 2, 5]\n11\n
# @lcpr case=end

# @lcpr case=start
# [2]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1]\n0\n
# @lcpr case=end

#

