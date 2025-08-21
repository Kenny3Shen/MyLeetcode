#
# @lc app=leetcode.cn id=1026 lang=python3
# @lcpr version=30204
#
# [1026] 节点与其祖先之间的最大差值
#


# @lcpr-template-start
from lc import *


# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        ans = 0

        def dfs(node):
            if not node:
                return (float("inf"), -float("inf"))
            nonlocal ans
            lmin, lmax = dfs(node.left)
            rmin, rmax = dfs(node.right)
            mi = min(lmin, rmin, node.val)
            ma = max(lmax, rmax, node.val)
            nonlocal ans
            ans = max(ans, node.val - mi, ma - node.val)
            return (mi, ma)

        dfs(root)
        return ans


# @lc code=end


#
# @lcpr case=start
# [8,3,10,1,6,null,14,null,null,4,7,13]\n
# @lcpr case=end

# @lcpr case=start
# [1,null,2,null,0,3]\n
# @lcpr case=end

#
