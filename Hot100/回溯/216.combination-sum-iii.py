#
# @lc app=leetcode.cn id=216 lang=python3
# @lcpr version=30204
#
# [216] 组合总和 III
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        path = []
        def dfs(i, target):
            if target == 0 and len(path) == k:
                ans.append(path.copy())
                return
            if target < 0 or i == 10 or len(path) > k:
                return
            # 不选
            dfs(i + 1, target)
            # 选
            path.append(i)
            dfs(i + 1, target - i)
            path.pop()
        dfs(1, n)
        return ans
# @lc code=end



#
# @lcpr case=start
# 3\n7\n
# @lcpr case=end

# @lcpr case=start
# 3\n9\n
# @lcpr case=end

# @lcpr case=start
# 4\n1\n
# @lcpr case=end

#

