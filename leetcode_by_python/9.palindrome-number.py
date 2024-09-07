#
# @lc app=leetcode.cn id=9 lang=python3
# @lcpr version=30204
#
# [9] 回文数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        (y, z) = (0, x)
        while z:
            y = y * 10 + z % 10
            z //= 10
        return x == y
# @lc code=end



#
# @lcpr case=start
# 121\n
# @lcpr case=end

# @lcpr case=start
# -121\n
# @lcpr case=end

# @lcpr case=start
# 10\n
# @lcpr case=end

#

