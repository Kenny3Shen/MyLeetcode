#
# @lc app=leetcode.cn id=77 lang=python3
# @lcpr version=30204
#
# [77] 组合
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        path = []

        def dfs(i: int) -> None:
            d = k - len(path)  # 还要选 d 个数
            if d == 0:  # 选好了
                ans.append(path.copy())
                return

            # 如果 i > d，可以不选 i
            if i > d:
                dfs(i - 1)

            # 选 i
            path.append(i)
            dfs(i - 1)
            path.pop()  # 恢复现场

        dfs(n)
        return ans


# @lc code=end


#
# @lcpr case=start
# 4\n2\n
# @lcpr case=end

# @lcpr case=start
# 1\n1\n
# @lcpr case=end

#
