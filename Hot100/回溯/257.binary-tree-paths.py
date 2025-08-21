#
# @lc app=leetcode.cn id=257 lang=python3
# @lcpr version=30204
#
# [257] 二叉树的所有路径
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
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        ans = []
        path = []
        def dfs(node):
            if not node:
                return
            path.append(str(node.val))
            if not node.left and not node.right:
                ans.append('->'.join(path))
            dfs(node.left)
            dfs(node.right)
            path.pop()
        dfs(root)
        return ans
# @lc code=end



#
# @lcpr case=start
# [1,2,3,null,5]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

