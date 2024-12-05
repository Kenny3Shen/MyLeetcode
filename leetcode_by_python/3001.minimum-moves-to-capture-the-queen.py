#
# @lc app=leetcode.cn id=3001 lang=python3
# @lcpr version=30204
#
# [3001] 捕获黑皇后需要的最少移动次数
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def minMovesToCaptureTheQueen(self, a: int, b: int, c: int, d: int, e: int, f: int) -> int:
        # m 在 l 和 r 之间（写不写等号都可以）
        def in_between(l: int, m: int, r: int) -> bool:
            return min(l, r) < m < max(l, r)

        # 车直接攻击到皇后 or 象直接攻击到皇后
        if a == e and (c != e or not in_between(b, d, f)) or \
           b == f and (d != f or not in_between(a, c, e)) or \
           c + d == e + f and (a + b != e + f or not in_between(c, a, e)) or \
           c - d == e - f and (a - b != e - f or not in_between(c, a, e)):
            return 1
        return 2
# @lc code=end



#
# @lcpr case=start
# 1\n1\n8\n8\n2\n3\n
# @lcpr case=end

# @lcpr case=start
# 5\n3\n3\n4\n5\n2\n
# @lcpr case=end

#

