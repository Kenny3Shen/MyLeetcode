#
# @lc app=leetcode.cn id=221 lang=python3
# @lcpr version=30204
#
# [221] 最大正方形
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        max_side = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    dp[i + 1][j + 1] = min(
                        dp[i][j], dp[i][j + 1], dp[i + 1][j]) + 1
                    max_side = max(max_side, dp[i + 1][j + 1])
        return max_side * max_side


# @lc code=end


#
# @lcpr case=start
# [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]\n
# @lcpr case=end

# @lcpr case=start
# [["0","1"],["1","0"]]\n
# @lcpr case=end

# @lcpr case=start
# [["0"]]\n
# @lcpr case=end

#
