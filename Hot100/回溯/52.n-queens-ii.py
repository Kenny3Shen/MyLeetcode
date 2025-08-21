#
# @lc app=leetcode.cn id=52 lang=python3
# @lcpr version=30204
#
# [52] N 皇后 II
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def totalNQueens(self, n: int) -> int:
        ans = 0
        col = []
        diag1 = [False] * (2 * n - 1)
        diag2 = [False] * (2 * n - 1)
        vis = [False] * n
        def dfs(i):
            nonlocal ans
            if i == n:
                ans += 1
                return
            for j in range(n):
                if not vis[j] and not diag1[i + j] and not diag2[i - j + n - 1]:
                    col.append(j)
                    vis[j] = diag1[i + j] = diag2[i - j + n - 1] = True
                    dfs(i + 1)
                    col.pop()
                    vis[j] = diag1[i + j] = diag2[i - j + n - 1] = False
        dfs(0)
        return ans
# @lc code=end



#
# @lcpr case=start
# 4\n
# @lcpr case=end

# @lcpr case=start
# 1\n
# @lcpr case=end

#

