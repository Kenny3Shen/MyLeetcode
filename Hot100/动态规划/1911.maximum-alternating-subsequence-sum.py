#
# @lc app=leetcode.cn id=1911 lang=python3
# @lcpr version=30204
#
# [1911] 最大子序列交替和
#

# f[i][0] 表示前 i 个数中长为偶数的子序列的最大交替和
# f[i][1] 表示前 i 个数中长为奇数的子序列的最大交替和。
# 初始时有 f[0][0]=0，f[0][1]=−∞。

# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)
        f = [[0] * 2 for _ in range(n + 1)]
        f[0][1] = -inf
        for i in range(n):
            # 不选 f[i+1] = f[i]
            # 选 f[i+1]
            # 当前为偶数位置，值为 前i-1个数中长为奇数的子序列的最大交替和 - nums[i]
            f[i + 1][0] = max(f[i][0], f[i][1] - nums[i])
            # 当前为奇数位置，值为 前i个数中长为偶数的子序列的最大交替和 + nums[i]
            f[i + 1][1] = max(f[i][1], f[i][0] + nums[i])
        return f[n][1]

# @lc code=end



#
# @lcpr case=start
# [4,2,5,3]\n
# @lcpr case=end

# @lcpr case=start
# [5,6,7,8]\n
# @lcpr case=end

# @lcpr case=start
# [6,2,1,2,4,5]\n
# @lcpr case=end

#

