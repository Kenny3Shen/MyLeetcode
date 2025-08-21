#
# @lc app=leetcode.cn id=198 lang=python3
# @lcpr version=30204
#
# [198] 打家劫舍
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        # @cache
        # def dfs(i):
        #     if i < 0:
        #         return 0
        #     res = max(dfs(i - 1), dfs(i - 2) + nums[i])
        #     return res
        # return dfs(n - 1)
    
        # f = [0] * (n + 2)
        # for i in range(n):
        #     f[i + 2] = max(f[i + 1], f[i] + nums[i])
        # return f[n + 1]
        f0 = f1 = 0
        for i in range(n):
            f2 = max(f1, f0 + nums[i])
            f0 = f1
            f1 = f2
        return f1


# @lc code=end


#
# @lcpr case=start
# [1,2,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [2,7,9,3,1]\n
# @lcpr case=end

#
