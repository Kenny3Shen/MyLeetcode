#
# @lc app=leetcode.cn id=152 lang=python3
# @lcpr version=30204
#
# [152] 乘积最大子数组
#


# @lcpr-template-start
from typing import List
# @lcpr-template-end
# @lc code=start
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # dp_max = nums.copy()
        # dp_min = nums.copy()
        # for i in range(1, len(nums)):
        #     dp_max[i] = max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i], nums[i])
        #     dp_min[i] = min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i], nums[i])
        # return max(dp_max)

        pre_max = pre_min = res = nums[0]
        for i in range(1, len(nums)):
            curr_max = max(pre_max * nums[i], pre_min * nums[i], nums[i])
            curr_min = min(pre_max * nums[i], pre_min * nums[i], nums[i])
            res = max(res, curr_max)
            pre_max, pre_min = curr_max, curr_min
        return res
# @lc code=end



#
# @lcpr case=start
# [2,3,-2,4]\n
# @lcpr case=end

# @lcpr case=start
# [-2,0,-1]\n
# @lcpr case=end

#

