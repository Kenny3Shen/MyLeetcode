#
# @lc app=leetcode.cn id=33 lang=python3
# @lcpr version=30204
#
# [33] 搜索旋转排序数组
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def find_min(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            mid = (left + right) // 2
            if nums[mid] < nums[-1]:
                right = mid
            else:
                left = mid + 1
        return left
    def search(self, nums: List[int], target: int) -> int:
        min_index = self.find_min(nums)
        # 考虑 target 与 nums[-1]的关系
        # 如果 target > nums[-1]
        # 说明在第一段递增区间 [0, min_index)
        # 如果 target < nums[-1]
        # 说明在第二段递增区间 [min_index, len(nums))
        if target > nums[-1]:
            res = bisect_left(nums, target, 0, min_index)
        else:
            res = bisect_left(nums, target, min_index, len(nums))
        
        # 实际上，bisect_left 返回的是插入位置
        # 如果 target 在 nums 中，返回 target 的位置
        # 如果 target 不在 nums 中，返回 target 的插入位置
        # 如果 target 在 nums 中，返回的位置一定小于 len(nums)
        # 如果 target 不在 nums 中，返回的位置可能等于 len(nums)
        # 但在这道题中，位置只会在左侧，所以不会等于 len(nums)
        
        return res if nums[res] == target else -1
        #return res if res < len(nums) and nums[res] == target else -1
        


# @lc code=end



#
# @lcpr case=start
# [4,5,6,7,0,1,2]\n0\n
# @lcpr case=end

# @lcpr case=start
# [4,5,6,7,0,1,2]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1]\n0\n
# @lcpr case=end

#

