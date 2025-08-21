#
# @lc app=leetcode.cn id=72 lang=python3
# @lcpr version=30204
#
# [72] 编辑距离
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        # word2 为空, word1[0:i] 只能删除 i 次
        for i in range(m + 1):
            dp[i][0] = i
        # word1 为空, word2[0:j] 只能插入 j 次
        for j in range(n + 1):
            dp[0][j] = j
        for i in range(m):
            for j in range(n):
                # 如果 word1[i] == word2[j], 则不需要操作
                if word1[i] == word2[j]:
                    dp[i + 1][j + 1] = dp[i][j]
                else:
                    # 插入, 删除, 替换
                    dp[i + 1][j + 1] = (
                        min(
                            dp[i][j + 1],  # 插入
                            dp[i + 1][j],  # 删除
                            dp[i][j],  # 替换
                        )
                        + 1
                    )
        return dp[m][n]


# @lc code=end


#
# @lcpr case=start
# "horse"\n"ros"\n
# @lcpr case=end

# @lcpr case=start
# "intention"\n"execution"\n
# @lcpr case=end

#
