#
# @lc app=leetcode.cn id=162 lang=python3
# @lcpr version=30204
#
# [162] 寻找峰值
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        # 考虑函数极大值点 x，有 x 左侧递增，x 右侧递减 
        # nums[mid] > nums[mid + 1] 表示 递减区间
        # 极值点在 mid 左侧
        # nums[mid] < nums[mid + 1] 表示 递增区间
        # 极值点在 mid 右侧
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > nums[mid + 1]:
                right = mid
            else:
                left = mid + 1
        return left
# @lc code=end



#
# @lcpr case=start
# [1,2,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,1,3,5,6,4]\n
# @lcpr case=end

#

