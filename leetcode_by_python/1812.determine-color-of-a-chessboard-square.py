#
# @lc app=leetcode.cn id=1812 lang=python3
# @lcpr version=30204
#
# [1812] 判断国际象棋棋盘中一个格子的颜色
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        return ord(coordinates[0]) % 2 != int(coordinates[1]) % 2
# @lc code=end



#
# @lcpr case=start
# "a1"\n
# @lcpr case=end

# @lcpr case=start
# "h3"\n
# @lcpr case=end

# @lcpr case=start
# "c7"\n
# @lcpr case=end

#

