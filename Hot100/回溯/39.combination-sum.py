#
# @lc app=leetcode.cn id=39 lang=python3
# @lcpr version=30204
#
# [39] 组合总和
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        path = []
        n = len(candidates)
        def dfs(i, target):
            if target == 0:
                ans.append(path[:])
                return
            if target < 0 or i == n:
                return
            # 不选
            dfs(i + 1, target)
            # 选
            path.append(candidates[i])
            dfs(i, target - candidates[i])
            path.pop()
        dfs(0, target)
        return ans
# @lc code=end



#
# @lcpr case=start
# [2,3,6,7]\n7\n
# @lcpr case=end

# @lcpr case=start
# [2,3,5]\n8\n
# @lcpr case=end

# @lcpr case=start
# [2]\n1\n
# @lcpr case=end

#

