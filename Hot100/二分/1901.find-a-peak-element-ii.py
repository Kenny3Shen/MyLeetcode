#
# @lc app=leetcode.cn id=1901 lang=python3
# @lcpr version=30204
#
# [1901] 寻找峰值 II
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        m, n = len(mat), len(mat[0])

        # 在列方向上进行二分查找
        left, right = 0, m

        while left < right:
            mid_row = (left + right) // 2

            # 找到当前行的最大值列索引
            # 则可以保证 mat[mid_row][max_col] 一定大于左右的元素
            max_col = 0
            for j in range(n):
                if mat[mid_row][j] > mat[mid_row][max_col]:
                    max_col = j

            # 检查是否是峰值
            is_peak = True

            # 检查上方元素（如果存在）
            if mid_row > 0 and mat[mid_row - 1][max_col] > mat[mid_row][max_col]:
                is_peak = False
                right = mid_row  # 峰值在上半部分
                continue

            # 检查下方元素（如果存在）
            if mid_row < m - 1 and mat[mid_row + 1][max_col] > mat[mid_row][max_col]:
                is_peak = False
                left = mid_row + 1  # 峰值在下半部分
                continue

            # 如果当前位置是峰值，返回结果
            if is_peak:
                return [mid_row, max_col]

        # 理论上不会执行到这里，因为题目保证存在峰值
        return [-1, -1]


# @lc code=end


#
# @lcpr case=start
# [[1,4],[3,2]]\n
# @lcpr case=end

# @lcpr case=start
# [[10,20,15],[21,30,14],[7,16,32]]\n
# @lcpr case=end

#
