#
# @lc app=leetcode.cn id=3019 lang=python3
# @lcpr version=30204
#
# [3019] 按键变更的次数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def countKeyChanges(self, s: str) -> int:
        res = 0
        for i in range(1, len(s)):
            if abs(ord(s[i]) - ord(s[i - 1])) == 32 or abs(ord(s[i]) - ord(s[i - 1])) == 0:
                continue
            res += 1
        return res
# @lc code=end



#
# @lcpr case=start
# "aAbBcC"\n
# @lcpr case=end

# @lcpr case=start
# "AaAaAaaA"\n
# @lcpr case=end

#

