#
# @lc app=leetcode.cn id=3 lang=python3
# @lcpr version=30204
#
# [3] 无重复字符的最长子串
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        ans = 0
        cnt = Counter()
        for j, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] > 1:
                cnt[s[i]] -= 1
                i += 1
            ans = max(ans, j - i + 1)
        return ans

# @lc code=end



#
# @lcpr case=start
# "abcabcbb"\n
# @lcpr case=end

# @lcpr case=start
# "bbbbb"\n
# @lcpr case=end

# @lcpr case=start
# "pwwkew"\n
# @lcpr case=end

#

