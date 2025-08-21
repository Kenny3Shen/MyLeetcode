#
# @lc app=leetcode.cn id=97 lang=python3
# @lcpr version=30204
#
# [97] 交错字符串
#


# @lcpr-template-start

# 如果s1的第i个字符等于s3的第i+j个字符，则dp[i][j] = dp[i-1][j]
# 如果s2的第j个字符等于s3的第i+j个字符，则dp[i][j] = dp[i][j-1]
# @lcpr-template-end
# @lc code=start
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n, t = len(s1), len(s2), len(s3)

        # 长度不匹配，直接返回False
        if m + n != t:
            return False

        # 创建DP数组并初始化
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = True

        # 初始化第一行
        for j in range(1, n + 1):
            dp[0][j] = dp[0][j - 1] and s2[j - 1] == s3[j - 1]

        # 初始化第一列
        for i in range(1, m + 1):
            dp[i][0] = dp[i - 1][0] and s1[i - 1] == s3[i - 1]

        # DP过程
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # 来自s1的字符
                if s1[i - 1] == s3[i + j - 1]:
                    dp[i][j] |= dp[i - 1][j]
                # 来自s2的字符
                if s2[j - 1] == s3[i + j - 1]:
                    dp[i][j] |= dp[i][j - 1]

        return dp[m][n]


# @lc code=end


#
# @lcpr case=start
# "aabcc"\n"dbbca"\n"aadbbcbcac"\n
# @lcpr case=end

# @lcpr case=start
# "aabcc"\n"dbbca"\n"aadbbbaccc"\n
# @lcpr case=end

# @lcpr case=start
# ""\n""\n""\n
# @lcpr case=end

#
