#
# @lc app=leetcode.cn id=131 lang=python3
# @lcpr version=30204
#
# [131] 分割回文串
#

from lc import *
# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        n = len(s)
        ans = []
        path = []
        def dfs(i):
            if i == n:
                ans.append(path[:])
                return 
            for j in range(i, n):
                t = s[i:j+1]
                if t == t[::-1]:
                    path.append(t)
                    dfs(j + 1)
                    path.pop()
        dfs(0)
        return ans

# @lc code=end



#
# @lcpr case=start
# "aab"\n
# @lcpr case=end

# @lcpr case=start
# "a"\n
# @lcpr case=end

#

