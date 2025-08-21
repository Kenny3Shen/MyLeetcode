#
# @lc app=leetcode.cn id=712 lang=python3
# @lcpr version=30204
#
# [712] 两个字符串的最小ASCII删除和
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            dp[i][0] = dp[i - 1][0] + ord(s1[i - 1])
        for j in range(1, n + 1):
            dp[0][j] = dp[0][j - 1] + ord(s2[j - 1])
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    # 删除s1[i-1]或者s2[j-1]
                    dp[i][j] = min(dp[i - 1][j] + ord(s1[i - 1]), dp[i][j - 1] + ord(s2[j - 1]))
        return dp[m][n]
# @lc code=end



#
# @lcpr case=start
# "sea"\n"eat"\n
# @lcpr case=end

# @lcpr case=start
# "delete"\n"leet"\n
# @lcpr case=end

#

