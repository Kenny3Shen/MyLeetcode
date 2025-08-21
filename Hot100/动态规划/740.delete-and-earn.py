#
# @lc app=leetcode.cn id=740 lang=python3
# @lcpr version=30204
#
# [740] 删除并获得点数
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    # 198. 打家劫舍
    def rob(self, nums: List[int]) -> int:
        f0 = f1 = 0
        for x in nums:
            f0, f1 = f1, max(f1, f0 + x)
        return f1

    def deleteAndEarn(self, nums: List[int]) -> int:
        a = [0] * (max(nums) + 1)
        for x in nums:
            a[x] += x  # 统计等于 x 的元素之和
        return self.rob(a)


# @lc code=end


#
# @lcpr case=start
# [3,4,2]\n
# @lcpr case=end

# @lcpr case=start
# [2,2,3,3,3,4]\n
# @lcpr case=end

#
