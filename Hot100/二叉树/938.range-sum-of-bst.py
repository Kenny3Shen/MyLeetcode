#
# @lc app=leetcode.cn id=938 lang=python3
# @lcpr version=30204
#
# [938] 二叉搜索树的范围和
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
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        if not root:
            return 0
        if root.val < low:
            return self.rangeSumBST(root.right, low, high)
        if root.val > high:
            return self.rangeSumBST(root.left, low, high)
        return root.val + self.rangeSumBST(root.left, low, high) + self.rangeSumBST(root.right, low, high)
# @lc code=end



#
# @lcpr case=start
# [10,5,15,3,7,null,18]\n7\n15\n
# @lcpr case=end

# @lcpr case=start
# [10,5,15,3,7,13,18,1,null,6]\n6\n10\n
# @lcpr case=end

#

