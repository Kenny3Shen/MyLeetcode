#
# @lc app=leetcode.cn id=2466 lang=python3
# @lcpr version=30204
#
# [2466] 统计构造好字符串的方案数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        MOD = 10**9 + 7
        
        # dp[i]: 构造长度为i的字符串的方案数
        dp = [0] * (high + 1)
        dp[0] = 1  # 空字符串的方案数为1
        
        # 计算每个长度的方案数
        for i in range(1, high + 1):
            # 添加zero个'0'
            if i >= zero:
                dp[i] = (dp[i] + dp[i - zero]) % MOD
                
            # 添加one个'1'
            if i >= one:
                dp[i] = (dp[i] + dp[i - one]) % MOD
        
        # 统计长度在[low, high]范围内的方案总数
        result = 0
        for i in range(low, high + 1):
            result = (result + dp[i]) % MOD
            
        return result

# @lc code=end



#
# @lcpr case=start
# 3\n3\n1\n1\n
# @lcpr case=end

# @lcpr case=start
# 2\n3\n1\n2\n
# @lcpr case=end

#

