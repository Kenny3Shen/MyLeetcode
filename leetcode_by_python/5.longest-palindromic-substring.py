#
# @lc app=leetcode.cn id=5 lang=python3
# @lcpr version=30204
#
# [5] 最长回文子串
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n < 2:
            return s  # 如果字符串长度小于2，直接返回字符串本身
        
        # 初始化动态规划表，dp[i][j]表示s[i:j+1]是否为回文子串
        dp = [[False] * n for _ in range(n)]
        max_len = 1  # 记录最长回文子串的长度
        start = 0  # 记录最长回文子串的起始位置
        
        # 所有长度为1的子串都是回文子串
        for i in range(n):
            dp[i][i] = True
        
        # 枚举子串长度从2到n
        for l in range(2, n + 1):
            for i in range(n):
                j = l + i - 1  # 计算子串的结束位置
                if j >= n:
                    break  # 如果结束位置超出字符串长度，跳出循环
                
                if s[i] != s[j]:
                    dp[i][j] = False  # 如果子串的首尾字符不相等，则不是回文子串
                else:
                    if j - i < 3:
                        dp[i][j] = True  # 如果子串长度小于等于3且首尾字符相等，则是回文子串
                    else:
                        dp[i][j] = dp[i + 1][j - 1]  # 否则，取决于去掉首尾字符后的子串是否为回文子串
                
                # 更新最长回文子串的长度和起始位置
                if dp[i][j] and j - i + 1 > max_len:
                    max_len = j - i + 1
                    start = i
        
        # 返回最长回文子串
        return s[start : start + max_len]


# @lc code=end


#
# @lcpr case=start
# "babad"\n
# @lcpr case=end

# @lcpr case=start
# "cbbd"\n
# @lcpr case=end

#
