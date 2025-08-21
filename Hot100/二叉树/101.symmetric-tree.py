#
# @lc app=leetcode.cn id=101 lang=python3
# @lcpr version=30204
#
# [101] 对称二叉树
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
    def isSame(self, p, q):
        if not p or not q:
            return p is q
        return p.val == q.val and self.isSame(p.left, q.right) and self.isSame(p.right, q.left)
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        return self.isSame(root.left, root.right)
# @lc code=end



#
# @lcpr case=start
# [1,2,2,3,4,4,3]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,2,null,3,null,3]\n
# @lcpr case=end

#

