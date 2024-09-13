#
# @lc app=leetcode.cn id=2390 lang=python3
# @lcpr version=30204
#
# [2390] 从字符串中移除星号
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def removeStars(self, s: str) -> str:
        res = []
        for c in s:
            if c != '*':
                res.append(c)
            else:
                res.pop()
        return ''.join(res)
# @lc code=end



#
# @lcpr case=start
# "leet**cod*e"\n
# @lcpr case=end

# @lcpr case=start
# "erase*****"\n
# @lcpr case=end

#

