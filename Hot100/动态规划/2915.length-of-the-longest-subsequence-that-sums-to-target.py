#
# @lc app=leetcode.cn id=2915 lang=python3
# @lcpr version=30204
#
# [2915] 和为目标值的最长子序列的长度
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        n = len(nums)
        f = [[-inf] * (target + 1) for _ in range(n + 1)]
        f[0][0] = 0
        for i, x in enumerate(nums):
            for c in range(target + 1):
                if x > c:
                    f[i + 1][c] = f[i][c]
                else:
                    f[i + 1][c] = max(f[i][c], f[i][c - nums[i]] + 1)
        ans = f[n][target]
        return ans if ans > -1 else -1

        dp = [-inf] * (target + 1)
        dp[0] = 0
        for num in nums:
            for j in range(target, num - 1, -1):
                dp[j] = max(dp[j], dp[j - num] + 1)
        return dp[target] if dp[target] > 0 else -1


# @lc code=end


#
# @lcpr case=start
# [1,2,3,4,5]\n9\n
# @lcpr case=end

# @lcpr case=start
# [4,1,3,2,1,5]\n7\n
# @lcpr case=end

# @lcpr case=start
# [1,1,5,4,5]\n3\n
# @lcpr case=end

#
