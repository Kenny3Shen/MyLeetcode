#
# @lc app=leetcode.cn id=153 lang=python3
# @lcpr version=30204
#
# [153] 寻找旋转排序数组中的最小值
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        # 第二个递增子数组的所有元素都小于第一个递增子数组的所有元素
        # nums[mid] < nums[right] 说明位于第二个子数组
        # 极小值在 左侧 或者 mid 位置
        # nums[mid] > nums[right] 说明位于第一个子数组
        # 极小值在 右侧
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < nums[right]:
                right = mid
            else:
                left = mid + 1
        return nums[left]
# @lc code=end



#
# @lcpr case=start
# [3,4,5,1,2]\n
# @lcpr case=end

# @lcpr case=start
# [4,5,6,7,0,1,2]\n
# @lcpr case=end

# @lcpr case=start
# [11,13,15,17]\n
# @lcpr case=end

#

