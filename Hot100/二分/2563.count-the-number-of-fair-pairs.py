#
# @lc app=leetcode.cn id=2563 lang=python3
# @lcpr version=30204
#
# [2563] 统计公平数对的数目
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def lower_bound(self, nums: List[int], target: int, left, right) -> int: 
        while left < right:
            mid = (left + right) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        return left
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        ans = 0
        # lower−nums[j]≤nums[i]≤upper−nums[j]
        # 找到lower−nums[j] 第一次出现的位置，则后面的都满足条件
        # 找到upper−nums[j] 最后一次出现的位置 则前面的都满足条件
        # 注意要在 [0, j) 中二分，因为题目要求两个下标 i < j
        for j, x in enumerate(nums):
            r = self.lower_bound(nums, upper - x + 1, 0, j) # <= upper-nums[j] 的 nums[i] 的个数
            l = self.lower_bound(nums, lower - x, 0, j)  # < lower-nums[j] 的 nums[i] 的个数
            ans += r - l
        return ans

# @lc code=end



#
# @lcpr case=start
# [0,1,7,4,4,5]\n3\n6\n
# @lcpr case=end

# @lcpr case=start
# [1,7,9,2,5]\n11\n11\n
# @lcpr case=end

#

