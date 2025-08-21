#
# @lc app=leetcode.cn id=494 lang=python3
# @lcpr version=30204
#
# [494] 目标和
#


# @lcpr-template-start
from lc import *

# @lcpr-template-end


def knapsack(capacity, weights, values):
    n = len(weights)

    def dfs(i, c):
        if c < 0:
            return 0
        if c < weights[i]:
            return dfs(i - 1, c)
        return max(dfs(i - 1, c), dfs(i - 1, c - weights[i]) + values[i])

    return dfs(n - 1, capacity)

# 设数组所有元素和为sum，我们将数组分成两部分：

# 一部分前面添加"+"号，设其和为P
# 另一部分前面添加"-"号，设其和为N
# 则有：

# P + N = sum
# P - N = target
# 解方程得：P = (sum + target)/2

# 所以问题转化为：从数组中选取一些数，使它们的和恰好为P的方案数
# @lc code=start
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        total = sum(nums)
        # 边界条件判断
        if total < abs(target) or (total + target) % 2 == 1:
            return 0
            
        # 计算需要凑成的正数和
        pos_sum = (total + target) // 2
        
        # dp[j]表示和为j的方案数
        dp = [0] * (pos_sum + 1)
        dp[0] = 1  # 和为0的方案数为1（什么都不选）
        
        # 01背包
        # 表示如果原来有dp[j-num]种方案可以得到和j-num，
        # 那么选择num后就有dp[j-num]种方案可以得到和j
        for num in nums:
            for j in range(pos_sum, num - 1, -1):
                dp[j] += dp[j - num]
                
        return dp[pos_sum]
        


# @lc code=end


#
# @lcpr case=start
# [1,1,1,1,1]\n3\n
# @lcpr case=end

# @lcpr case=start
# [1]\n1\n
# @lcpr case=end

#
