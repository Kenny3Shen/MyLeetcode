#
# @lc app=leetcode.cn id=2331 lang=python3
# @lcpr version=30204
#
# [2331] 计算布尔二叉树的值
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
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        if not root.left and not root.right:
            return True if root.val == 1 else False
        if root.val == 2:
            return self.evaluateTree(root.left) or self.evaluateTree(root.right)
        else:
            return self.evaluateTree(root.left) and self.evaluateTree(root.right)
# @lc code=end



#
# @lcpr case=start
# [2,1,3,null,null,0,1]\n
# @lcpr case=end

# @lcpr case=start
# [0]\n
# @lcpr case=end

#

