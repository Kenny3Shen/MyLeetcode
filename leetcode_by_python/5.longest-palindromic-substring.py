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
        left, right = 0, 0

        def expandAroundCenter(s: str, left: int, right: int):
            while left >= 0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
            # left + 1, right - 1 是最后一个相等的位置
            return right - left - 1, left + 1, right - 1

        for i in range(n):
            len1, l1, r1 = expandAroundCenter(s, i, i)
            len2 = 0
            if i + 1 < n:
                len2, l2, r2 = expandAroundCenter(s, i, i + 1)
            max_len = max(len1, len2)
            if max_len > right - left:
                if max_len == len1:
                    left, right = l1, r1
                else:
                    left, right = l2, r2

        return s[left : right + 1]


# @lc code=end


#
# @lcpr case=start
# "babad"\n
# @lcpr case=end

# @lcpr case=start
# "cbbd"\n
# @lcpr case=end

#
