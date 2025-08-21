#
# @lc app=leetcode.cn id=2266 lang=python3
# @lcpr version=30204
#
# [2266] 统计打字方案数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
mapp = {
    '2': 'abc',
    '3': 'def',
    '4': 'ghi',
    '5': 'jkl',
    '6': 'mno',
    '7': 'pqrs',
    '8': 'tuv',
    '9': 'wxyz'
}
class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        MOD = 10**9 + 7
        n = len(pressedKeys)
        dp = [0] * (n + 1)  # dp[i]表示处理前i个字符的方案数
        dp[0] = 1  # 空字符串的方案数为1
        
        for i in range(1, n + 1):
            # 当前字符
            curr = pressedKeys[i - 1]
            
            # 添加当前字符的方案数
            dp[i] = (dp[i] + dp[i - 1]) % MOD
            
            # 检查连续相同字符
            # 对大多数按键，最多可以连续按3次（如'2'可以是'a','b','c'）
            # 对于'7'和'9'，最多可以连续按4次
            max_press = 4 if curr in ['7', '9'] else 3
            
            # 尝试不同的按键次数
            j = i - 1
            count = 1
            
            # 向前查看连续相同的字符，计算不同分组方式的方案数
            while j > 0 and pressedKeys[j - 1] == curr and count < max_press:
                dp[i] = (dp[i] + dp[j - 1]) % MOD
                j -= 1
                count += 1
        
        return dp[n]
# @lc code=end



#
# @lcpr case=start
# "22233"\n
# @lcpr case=end

# @lcpr case=start
# "222222222222222222222222222222222222"\n
# @lcpr case=end

#

