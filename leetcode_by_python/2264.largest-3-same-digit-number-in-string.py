#
# @lc app=leetcode.cn id=2264 lang=python3
# @lcpr version=30204
#
# [2264] 字符串中最大的 3 位相同数字
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def largestGoodInteger(self, num: str) -> str:
        max_char = ""
        for i in range(len(num)-2):
            if num[i] == num[i+1] == num[i+2]:
                max_char = max(max_char, num[i])
        return max_char * 3
# @lc code=end



#
# @lcpr case=start
# "6777133339"\n
# @lcpr case=end

# @lcpr case=start
# "2300019"\n
# @lcpr case=end

# @lcpr case=start
# "42352338"\n
# @lcpr case=end

#

