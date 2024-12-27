#
# @lc app=leetcode.cn id=3142 lang=python3
# @lcpr version=30204
#
# [3142] 判断矩阵是否满足条件
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def satisfiesConditions(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        m = len(grid[0])
        for i in range(n):
            for j in range(m):
                if i + 1 < n:
                    if grid[i][j] != grid[i + 1][j]:
                        return False
                if j + 1 < m:
                    if grid[i][j] == grid[i][j + 1]:
                        return False
        return True
# @lc code=end



#
# @lcpr case=start
# [[1,0,2],[1,0,2]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,1,1],[0,0,0]]\n
# @lcpr case=end

# @lcpr case=start
# [[1],[2],[3]]\n
# @lcpr case=end

#

