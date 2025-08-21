#
# @lc app=leetcode.cn id=1143 lang=python3
# @lcpr version=30204
#
# [1143] 最长公共子序列
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            for j in range(n):
                dp[i + 1][j + 1] = max(
                    dp[i + 1][j],
                    dp[i][j + 1],
                    dp[i][j] + (s1[i] == s2[j]),
                )
        return dp[m][n]


# @lc code=end


#
# @lcpr case=start
# "abcde"\n"ace"\n
# @lcpr case=end

# @lcpr case=start
# "abc"\n"abc"\n
# @lcpr case=end

# @lcpr case=start
# "abc"\n"def"\n
# @lcpr case=end

#
