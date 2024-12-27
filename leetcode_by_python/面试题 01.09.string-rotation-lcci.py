#
# @lc app=leetcode.cn id= 面试题 01.09 lang=python3
# @lcpr version=30204
#
# [ 面试题 01.09] 字符串轮转
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        return s1 in s2 + s2
# @lc code=end



#
# @lcpr case=start
# "waterbottle"\n"erbottlewat"\n
# @lcpr case=end

# @lcpr case=start
# "aa"\n"aba"\n
# @lcpr case=end

#

