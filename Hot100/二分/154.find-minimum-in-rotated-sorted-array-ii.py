#
# @lc app=leetcode.cn id=154 lang=python3
# @lcpr version=30204
#
# [154] 寻找旋转排序数组中的最小值 II
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        left = 0
        right = n - 1
        # 如果左端的元素等于右端的元素，我们可以安全地跳过左端的元素，
        # 因为即使它是最小值，右端也有一个相同的值
        while left < right and nums[left] == nums[-1]:
            left += 1

        while left < right:
            mid = (left + right) // 2
            # mid 位于第二个递增子数组或者是重复元素
            if nums[mid] <= nums[-1]:
                right = mid
            else:
                left = mid + 1
        return nums[left]


# @lc code=end


#
# @lcpr case=start
# [1,3,5]\n
# @lcpr case=end

# @lcpr case=start
# [2,2,2,0,1]\n
# @lcpr case=end

#
