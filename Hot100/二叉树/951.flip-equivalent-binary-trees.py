#
# @lc app=leetcode.cn id=951 lang=python3
# @lcpr version=30204
#
# [951] 翻转等价二叉树
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
    def flipEquiv(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        def dfs(node1, node2):
            if not node1 or not node2:
                return node1 is node2
            if node1.val != node2.val:
                return False
            if dfs(node1.left, node2.left) and dfs(node1.right, node2.right):
                return True
            if dfs(node1.left, node2.right) and dfs(node1.right, node2.left):
                return True
            return False
        return dfs(root1, root2)
# @lc code=end



#
# @lcpr case=start
# [1,2,3,4,5,6,null,null,null,7,8]\n[1,3,2,null,6,4,5,null,null,null,null,8,7]\n
# @lcpr case=end

# @lcpr case=start
# []\n[]\n
# @lcpr case=end

# @lcpr case=start
# []\n[1]\n
# @lcpr case=end

#

