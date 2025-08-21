#
# @lc app=leetcode.cn id=76 lang=python3
# @lcpr version=30204
#
# [76] 最小覆盖子串
#


# @lcpr-template-start
from collections import Counter
# @lcpr-template-end
# @lc code=start
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        cnt_s = Counter()
        cnt_t = Counter(t)
        i = 0
        ans = len(s) + 1
        ans_start = -1
        for j, c in enumerate(s):
            cnt_s[c] += 1
            while cnt_s >= cnt_t:
                if j - i + 1 < ans:
                    ans = j - i + 1
                    ans_start = i
                cnt_s[s[i]] -= 1
                i += 1
        return s[ans_start: ans_start + ans] if ans_start != -1 else ""

# @lc code=end



#
# @lcpr case=start
# "ADOBECODEBANC"\n"ABC"\n
# @lcpr case=end

# @lcpr case=start
# "a"\n"a"\n
# @lcpr case=end

# @lcpr case=start
# "a"\n"aa"\n
# @lcpr case=end

#

