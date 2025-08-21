#
# @lc app=leetcode.cn id=111 lang=python3
# @lcpr version=30204
#
# [111] 二叉树的最小深度
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
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        left_depth = self.minDepth(root.left)
        right_depth = self.minDepth(root.right)
        # 需要特别处理单侧子树的情况
        if root.left is None:
            return 1 + right_depth
        if root.right is None:
            return 1 + left_depth
        return 1 + min(left_depth, right_depth)
# @lc code=end



#
# @lcpr case=start
# [3,9,20,null,null,15,7]\n
# @lcpr case=end

# @lcpr case=start
# [2,null,3,null,4,null,5,null,6]\n
# @lcpr case=end

#

