#
# @lc app=leetcode.cn id=51 lang=python3
# @lcpr version=30204
#
# [51] N 皇后
#

# 不同行，不同列→每行每列恰好有一个皇后
# 证明：反证法+鸽巢原理
# 用一个长为n的数组col记录皇后的位置
# 即第行的皇后在第col列
# 那么col必须是一个0到n－1的排列
# 示例1左图col=[1,3,0,2]，右图col=[2,0,3,1]

# 这行代码用于检查是否可以在位置 (r, c) 放置皇后，主要判断三个条件：

# 列是否已被占用 not vis[c]
# 左上-右下对角线是否已被占用 not diag1[r + c]
# 右上-左下对角线是否已被占用 not diag2[r - c + n - 1]
# 对角线判断原理
# 左上-右下对角线：

# 对于同一条左上-右下对角线上的所有格子，它们的 行号-列号 是固定值
# 例如：(0,0), (1,1), (2,2), (3,3) 都在同一条对角线，r+c=0, 2, 4, 6
# 右上-左下对角线：

# 对于同一条右上-左下对角线上的所有格子，它们的 行号-列号 是固定值
# 例如：(0,3), (1,2), (2,1), (3,0) 都在同一条对角线，r-c=-3, -1, 1, 3
# 为了避免负索引，加上 n-1 使所有索引为非负数

# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []  # 存储所有符合条件的N皇后布局
        col = []
        vis = [False] * n  # 记录每一列是否被占用
        diag1 = [False] * (2 * n - 1)  # 记录左上到右下对角线是否被占用
        diag2 = [False] * (2 * n - 1)  # 记录右上到左下对角线是否被占用

        def dfs(r):
            # 如果已经处理完所有行，找到一个有效解
            if r == n:
                # 将列位置转换为棋盘表示：每个元素是一行，'Q'表示皇后，'.'表示空位
                ans.append(["." * c + "Q" + "." * (n - c - 1) for c in col])
                return

            # 尝试在当前行的每个可用列放置皇后
            for c in range(n):
                # 检查对角线冲突
                if not vis[c] and not diag1[r + c] and not diag2[r - c + n - 1]:
                    col.append(c) # 记录当前列
                    vis[c] = diag1[r + c] = diag2[r - c + n - 1] = True
                    dfs(r + 1)  # 递归处理下一行，更新可用列集合
                    vis[c] = diag1[r + c] = diag2[r - c + n - 1] = False
                    col.pop() # 回溯，撤销当前列
        # 从第0行开始，初始时所有列都可用
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
