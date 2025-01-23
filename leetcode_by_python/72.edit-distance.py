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
        # 获取两个字符串的长度
        m, n = len(word1), len(word2)

        # 初始化dp表
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        # 初始化边界条件
        for i in range(m + 1):
            dp[i][0] = i  # word1的前i个字符转换为空串需要删除i次
        for j in range(n + 1):
            dp[0][j] = j  # 空串转换为word2的前j个字符需要插入j次

        # 填充dp表
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    # 如果字符相同，不需要额外操作
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    # 取三种操作中的最小值
                    dp[i][j] = min(
                        dp[i - 1][j] + 1,  # 删除word1[i-1]
                        dp[i][j - 1] + 1,  # 在word1插入word2[j-1]
                        dp[i - 1][j - 1] + 1,  # 将word1[i-1]替换为word2[j-1]
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
