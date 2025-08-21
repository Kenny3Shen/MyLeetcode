#
# @lc app=leetcode.cn id=2730 lang=python3
# @lcpr version=30204
#
# [2730] 找到最长的半重复子字符串
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        ans = 1 
        i = 0
        rep = 0
        n = len(s)
        for j in range(1, n):
            if s[j] == s[j - 1]:
                rep += 1
            while rep > 1:
                if s[i] == s[i + 1]:
                    rep -= 1
                i += 1
            ans = max(ans, j - i + 1)
        return ans
# @lc code=end



#
# @lcpr case=start
# "52233"\n
# @lcpr case=end

# @lcpr case=start
# "5494"\n
# @lcpr case=end

# @lcpr case=start
# "1111111"\n
# @lcpr case=end

#

