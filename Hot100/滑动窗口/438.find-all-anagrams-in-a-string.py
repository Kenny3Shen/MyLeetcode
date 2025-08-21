#
# @lc app=leetcode.cn id=438 lang=python3
# @lcpr version=30204
#
# [438] 找到字符串中所有字母异位词
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []
        
        ans = []
        i = 0
        cnt = Counter(p)
        for j, c in enumerate(s):
            cnt[c] -= 1
            while cnt[c] < 0:
                cnt[s[i]] += 1
                i += 1
            if j - i + 1 == len(p):
                ans.append(i)
        return ans
# @lc code=end



#
# @lcpr case=start
# "cbaebabacd"\n"abc"\n
# @lcpr case=end

# @lcpr case=start
# "abab"\n"ab"\n
# @lcpr case=end

#

