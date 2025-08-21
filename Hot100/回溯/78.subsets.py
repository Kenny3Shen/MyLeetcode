#
# @lc app=leetcode.cn id=78 lang=python3
# @lcpr version=30204
#
# [78] 子集
#
from lc import *

# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        path = []

        def dfs(i):
            # 每个节点都是一个解
            ans.append(path[:])
            if i == n:
                return
            # 枚举选择
            for j in range(i, n):
                path.append(nums[j])
                dfs(j + 1)
                path.pop()
        dfs(0)
        return ans


# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [0]\n
# @lcpr case=end

#

