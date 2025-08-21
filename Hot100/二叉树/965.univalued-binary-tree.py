#
# @lc app=leetcode.cn id=965 lang=python3
# @lcpr version=30204
#
# [965] 单值二叉树
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
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        def dfs(node, val):
            if not node:
                return True
            if node.val != val:
                return False
            return dfs(node.left, val) and dfs(node.right, val)
        return dfs(root, root.val)
        
# @lc code=end



#
# @lcpr case=start
# [1,1,1,1,1,null,1]\n
# @lcpr case=end

# @lcpr case=start
# [2,2,2,5,2]\n
# @lcpr case=end

#

