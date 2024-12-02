#
# @lc app=leetcode.cn id=3274 lang=python3
# @lcpr version=30204
#
# [3274] 检查棋盘方格颜色是否相同
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def checkTwoChessboards(self, s: str, t: str) -> bool:
        return (ord(s[0]) + ord(s[1])) % 2 == (ord(t[0]) + ord(t[1])) % 2
# @lc code=end



#
# @lcpr case=start
# "a1"\n"c3"\n
# @lcpr case=end

# @lcpr case=start
# "a1"\n"h3"\n
# @lcpr case=end

#

