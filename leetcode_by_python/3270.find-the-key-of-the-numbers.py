#
# @lc app=leetcode.cn id=3270 lang=python3
# @lcpr version=30204
#
# [3270] 求出数字答案
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        a = min(num1 // 1000, num2 // 1000, num3 // 1000)
        b = min(num1 // 100 % 10, num2 // 100 % 10, num3 // 100 % 10)
        c = min(num1 // 10 % 10, num2 // 10 % 10, num3 // 10 % 10)
        d = min(num1 % 10, num2 % 10, num3 % 10)
        return a * 1000 + b * 100 + c * 10 + d
# @lc code=end



#
# @lcpr case=start
# 1\n10\n1000\n
# @lcpr case=end

# @lcpr case=start
# 987\n879\n798\n
# @lcpr case=end

# @lcpr case=start
# 1\n2\n3\n
# @lcpr case=end

#

