#
# @lc app=leetcode.cn id=59 lang=python3
# @lcpr version=30204
#
# [59] 螺旋矩阵 II
#

from typing import List
# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0 * n] * n]
        start, end = 1, n * n
        left, right, top, bottom = 0, n - 1, 0, n - 1
        while start <= end:
            for i in range(left, right + 1):
                res[top][i] = start
                start += 1
            top += 1
            for i in range(top, bottom + 1):
                res[i][right] = start
                start += 1
            right -= 1
            for i in range(right, left - 1, -1):
                res[bottom][i] = start
                start += 1
            bottom -= 1
            for i in range(bottom, top - 1, -1):
                res[i][left] = start
                start += 1
            left += 1
        return res

# @lc code=end



#
# @lcpr case=start
# 3\n
# @lcpr case=end

# @lcpr case=start
# 1\n
# @lcpr case=end

#

