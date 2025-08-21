#
# @lc app=leetcode.cn id=213 lang=python3
# @lcpr version=30204
#
# [213] 打家劫舍 II
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        # 如果偷 nums[0]，那么 nums[1] 和 nums[n−1] 不能偷，问题变成从 nums[2:n−2]
        # 如果不偷 nums[0]，那么问题变成从 nums[1] 到 nums[n−1] 的非环形版本
        def dp(nums):
            n = len(nums)
            f = [0] * (n + 2)
            for i in range(2, n + 2):
                f[i] = max(f[i - 1], f[i - 2] + nums[i - 2])
            return f[-1]

        return max(nums[0] + dp(nums[2:-1]), dp(nums[1:]))


# @lc code=end


#
# @lcpr case=start
# [2,3,2]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

#
