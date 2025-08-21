#
# @lc app=leetcode.cn id=2529 lang=python3
# @lcpr version=30204
#
# [2529] 正整数和负整数的最大计数
#


# @lcpr-template-start
from typing import List
from bisect import bisect_left, bisect_right
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
    
    def upper_bound(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums)
        while left < right:
            mid = (left + right) // 2
            if nums[mid] > target:
                right = mid
            else:
                left = mid + 1
        return left
    def maximumCount(self, nums: List[int]) -> int:
        # 0 既不是正整数也不是负整数。
        # 第一个 0, 也就是第一个非负数
        zero_start = bisect_left(nums, 0, 0, len(nums))
        # 最后一个 0, 也就是最后一个非正数
        zero_end = bisect_right(nums, 0, 0, len(nums))
        neg = zero_start - 0
        pos = len(nums) - zero_end
        return max(neg, pos)
# @lc code=end



#
# @lcpr case=start
# [-2,-1,-1,1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [-3,-2,-1,0,0,1,2]\n
# @lcpr case=end

# @lcpr case=start
# [5,20,66,1314]\n
# @lcpr case=end

#

