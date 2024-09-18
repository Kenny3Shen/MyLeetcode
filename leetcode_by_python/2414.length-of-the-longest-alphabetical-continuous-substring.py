#
# @lc app=leetcode.cn id=2414 lang=python3
# @lcpr version=30204
#
# [2414] 最长的字母序连续子字符串的长度
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0
        ans = 1
        cnt = 1
        for i in range(1, n):
            if ord(s[i]) - ord(s[i - 1]) == 1:
                cnt += 1
            else:
                cnt = 1
            ans = max(ans, cnt)
        return ans 
# @lc code=end



#
# @lcpr case=start
# "abacaba"\n
# @lcpr case=end

# @lcpr case=start
# "abcde"\n
# @lcpr case=end

#

