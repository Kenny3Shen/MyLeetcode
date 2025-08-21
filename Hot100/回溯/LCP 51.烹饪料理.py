#
# @lc app=leetcode.cn id=LCP 51 lang=python3
# @lcpr version=30204
#
# [LCP 51] 烹饪料理
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
class Solution:
    def perfectMenu(
        self,
        materials: List[int],
        cookbooks: List[List[int]],
        attribute: List[List[int]],
        limit: int,
    ) -> int:
        # 每种料理只能制作一次
        ans = -1
        n = len(cookbooks)

        def dfs(i, cur_x, cur_y):
            nonlocal ans, materials
            if any(x < 0 for x in materials):
                return
            if i == n:
                if cur_y >= limit:
                    ans = max(ans, cur_x)
                return
            # not choose
            dfs(i + 1, cur_x, cur_y)
            # choose
            for j in range(5):
                materials[j] -= cookbooks[i][j]
            dfs(i + 1, cur_x + attribute[i][0], cur_y + attribute[i][1])
            for j in range(5):
                materials[j] += cookbooks[i][j]

        dfs(0, 0, 0)
        return ans


# @lc code=end


#
# @lcpr case=start
# [3,2,4,1\n[[1,1,0,1,2],[2,1,4,0,0],[3,2,4,1\n[[3,2],[2,4],[7\n5`>\n
# @lcpr case=end

# @lcpr case=start
# [10,10,10,10\n[[1,1,1,1,1],[3,3,3,3,3],[10,10,10,10\n[[5,5],[6,6],[10\n1`>\n
# @lcpr case=end

#
