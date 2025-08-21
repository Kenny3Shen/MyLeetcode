#
# @lc app=leetcode.cn id=46 lang=python3
# @lcpr version=30204
#
# [46] 全排列
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        path = []
        n = len(nums)
        vis = [False] * n
        def dfs(i):
            if i == n:
                ans.append(path[:])
                return
            for j in range(n):
                if not vis[j]:
                    vis[j] = True
                    path.append(nums[j])
                    dfs(i + 1)
                    path.pop()
                    vis[j] = False
        dfs(0)
        return ans
                   
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [0,1]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

