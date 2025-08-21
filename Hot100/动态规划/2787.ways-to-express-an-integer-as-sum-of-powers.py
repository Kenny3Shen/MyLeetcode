#
# @lc app=leetcode.cn id=2787 lang=python3
# @lcpr version=30204
#
# [2787] 将一个数字表示成幂的和的方案数
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        # 把 n 看成背包容量，1^x, 2^x, 3^x, ..., n^x 看成物品
        # dp[i][j] 表示前 i 个物品中选取若干个物品，使得它们的和为 j 的方案数
        # mod = 10**9 + 7
        # dp = [[0] * (n + 1) for _ in range(n + 1)]
        # # dp[0][0] = 1 because 0^x = 0
        # dp[0][0] = 1
        # for i in range(1, n + 1):
        #     for j in range(1, n + 1):
        #         dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i ** x]) % mod
        # return dp[n][n]

        # 把 n 看成背包容量，1^x, 2^x, 3^x, ..., n^x 看成物品, 0-1背包
        # dp[i] 表示选取若干个物品，使得它们的和为 i 的方案数
        mod = 10**9 + 7
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            if i**x > n:
                break
            for j in range(n, i - 1, -1):
                if j >= i**x:
                    dp[j] = (dp[j] + dp[j - i**x]) % mod
        return dp[n]


# @lc code=end


#
# @lcpr case=start
# 10\n2\n
# @lcpr case=end

# @lcpr case=start
# 4\n1\n
# @lcpr case=end

#
