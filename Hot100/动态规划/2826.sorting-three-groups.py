#
# @lc app=leetcode.cn id=2826 lang=python3
# @lcpr version=30204
#
# [2826] 将三个组排序
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        
        # dp[i][j] 表示将前i个元素变成非递减序列且结尾值为j所需的最小操作次数
        # j取值为1,2,3，对应数组中允许的三个值
        dp = [[float('inf')] * 4 for _ in range(n + 1)]
        
        # 初始化：0个元素的基础情况
        dp[0][1] = dp[0][2] = dp[0][3] = 0
        
        for i in range(1, n + 1):
            # 当前元素nums[i-1]
            curr = nums[i-1]
            
            # 将当前元素变为1
            # 这样前i-1个元素结尾也只能是1
            dp[i][1] = dp[i-1][1] + (1 != curr)
            
            # 将当前元素变为2
            # 前i-1个元素结尾可以是1或2
            dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + (2 != curr)
            
            # 将当前元素变为3
            # 前i-1个元素结尾可以是1,2或3
            dp[i][3] = min(dp[i-1][1], dp[i-1][2], dp[i-1][3]) + (3 != curr)
        
        # 最终结果是将所有元素都处理完，且结尾是1,2,3任一值的最小操作次数
        return min(dp[n][1], dp[n][2], dp[n][3])
# @lc code=end



#
# @lcpr case=start
# [2,1,3,2,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,3,2,1,3,3]\n
# @lcpr case=end

# @lcpr case=start
# [2,2,2,2,3,3]\n
# @lcpr case=end

#

