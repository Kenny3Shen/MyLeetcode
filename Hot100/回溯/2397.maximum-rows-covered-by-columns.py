#
# @lc app=leetcode.cn id=2397 lang=python3
# @lcpr version=30204
#
# [2397] 被列覆盖的最多行数
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def maximumRows(self, matrix: List[List[int]], numSelect: int) -> int:
        m, n = len(matrix), len(matrix[0])
        ans = 0
        cnt = [sum(matrix[i]) for i in range(m)]

        def dfs(i, sel, cover):
            nonlocal ans
            if i == n or sel == numSelect:
                final_cover = 0
                for j in range(m):
                    if cover[j] == cnt[j]:
                        final_cover += 1
                ans = max(ans, final_cover)
                return
            # not choose
            dfs(i + 1, sel, cover)
            # choose
            cur_cover = cover[:]
            for j in range(m):
                cur_cover[j] += matrix[j][i]
            dfs(i + 1, sel + 1, cur_cover)

        dfs(0, 0, [0] * m)
        return ans


# @lc code=end


#
# @lcpr case=start
# [[0,0,0],[1,0,1],[0,1,1],[0,0,1]]\n2\n
# @lcpr case=end

# @lcpr case=start
# [[1],[0]]\n1\n
# @lcpr case=end

#
