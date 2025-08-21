#
# @lc app=leetcode.cn id=34 lang=python3
# @lcpr version=30204
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def lower_bound(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        return left

    def searchRange(self, nums: List[int], target: int) -> List[int]:
        first_index = self.lower_bound(nums, target)
        if first_index == len(nums) or nums[first_index] != target:
            return [-1, -1]
        # self.lower_bound(nums, target + 1) 表示 target + 1 的位置
        # 或者第一个大于 target 的位置
        last_index = self.lower_bound(nums, target + 1) - 1
        return [first_index, last_index]


# @lc code=end


#
# @lcpr case=start
# [5,7,7,8,8,10]\n8\n
# @lcpr case=end

# @lcpr case=start
# [5,7,7,8,8,10]\n6\n
# @lcpr case=end

# @lcpr case=start
# []\n0\n
# @lcpr case=end

#
