#
# @lc app=leetcode.cn id=784 lang=python3
# @lcpr version=30204
#
# [784] 字母大小写全排列
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans = []
        path = []
        n = len(s)
        def dfs(i):
            if i == n:
                ans.append("".join(path))
                return
            if s[i].isdigit():
                path.append(s[i])
                dfs(i + 1)
                path.pop()
            else:
                path.append(s[i].lower())
                dfs(i + 1)
                path.pop()
                path.append(s[i].upper())
                dfs(i + 1)
                path.pop()
        dfs(0)
        return ans

# @lc code=end



#
# @lcpr case=start
# "a1b2"\n
# @lcpr case=end

# @lcpr case=start
# "3z4"\n
# @lcpr case=end

#

