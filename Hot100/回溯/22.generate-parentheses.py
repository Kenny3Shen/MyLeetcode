#
# @lc app=leetcode.cn id=22 lang=python3
# @lcpr version=30204
#
# [22] 括号生成
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        path = []
        m = n * 2
        def dfs(i, l, r):
            if i == m:
                ans.append("".join(path))
                return
            if l < n:
                path.append("(")
                dfs(i + 1, l + 1, r)
                path.pop()
            if r < l:
                path.append(")")
                dfs(i + 1, l, r + 1)
                path.pop()
        dfs(0, 0, 0)
        return ans

# @lc code=end



#
# @lcpr case=start
# 3\n
# @lcpr case=end

# @lcpr case=start
# 1\n
# @lcpr case=end

#

