#
# @lc app=leetcode.cn id=1458 lang=python3
# @lcpr version=30204
#
# [1458] 两个子序列的最大点积
#


# @lcpr-template-start
from lc import *


# dp[i][j] = max(nums1[i-1] * nums2[j-1] + max(dp[i-1][j-1], 0), dp[i-1][j], dp[i][j-1])
# @lcpr-template-end
# @lc code=start
class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)

        # 初始化DP数组
        dp = [[float("-inf")] * (n + 1) for _ in range(m + 1)]

        # 动态规划过程
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # 选择当前元素组成点积
                current_product = nums1[i - 1] * nums2[j - 1]

                dp[i][j] = max(
                    current_product,  # 仅使用当前元素
                    current_product
                    + max(0, dp[i - 1][j - 1]),  # 当前点积 + 之前的最大点积(如果为正)
                    dp[i - 1][j],  # 不使用nums1[i-1]
                    dp[i][j - 1],  # 不使用nums2[j-1]
                )

        return dp[m][n]


# @lc code=end


#
# @lcpr case=start
# [2,1,-2,5]\n[3,0,-6]\n
# @lcpr case=end

# @lcpr case=start
# [3,-2]\n[2,-6,7]\n
# @lcpr case=end

# @lcpr case=start
# [-1,-1]\n[1,1]\n
# @lcpr case=end

#
