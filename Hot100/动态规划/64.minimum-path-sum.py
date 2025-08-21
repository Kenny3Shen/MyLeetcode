#
# @lc app=leetcode.cn id=64 lang=python3
# @lcpr version=30204
#
# [64] 最小路径和
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        f = [[inf] * (n + 1) for _ in range(m + 1)]
        f[0][1] = 0
        for i in range(m):
            for j in range(n):
                f[i + 1][j + 1] = min(f[i][j + 1], f[i + 1][j]) + grid[i][j]
        return f[m][n]
# @lc code=end



#
# @lcpr case=start
# [[1,3,1],[1,5,1],[4,2,1]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,2,3],[4,5,6]]\n
# @lcpr case=end

#

