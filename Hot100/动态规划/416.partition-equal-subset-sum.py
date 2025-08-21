#
# @lc app=leetcode.cn id=416 lang=python3
# @lcpr version=30204
#
# [416] 分割等和子集
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # 1. 确定dp数组以及下标的含义
        # dp[i][j] 表示从数组的 [0, i] 下标范围内选取若干个正整数（可以是 0 个），
        # 是否存在一种选取方案使得被选取的正整数的和等于 j。
        # 2. 确定递推公式
        # 对于 dp[i][j]，可以分为两种情况：
        # 不选 nums[i]，如果不选 nums[i]，dp[i][j] = dp[i - 1][j]；
        # 选 nums[i]，如果选 nums[i]，dp[i][j] = dp[i - 1][j - nums[i]]。
        # 3. dp数组如何初始化
        # dp[0][0] = True，表示不选取任何正整数时被选取的正整数和为 0 是成立的。
        # 4. 确定遍历顺序
        # 遍历顺序为先遍历物品，再遍历背包容量。
        n = len(nums)
        total = sum(nums)
        if total % 2 != 0:
            return False
        target = total // 2
        dp = [[False] * (target + 1) for _ in range(n + 1)]
        dp[0][0] = True
        for i in range(n):
            for j in range(target + 1):
                if j >= nums[i]:
                    dp[i + 1][j] = dp[i][j] or dp[i][j - nums[i]]
                else:
                    dp[i + 1][j] = dp[i][j]
        return dp[n][target]


# @lc code=end


#
# @lcpr case=start
# [1,5,11,5]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,5]\n
# @lcpr case=end

#
