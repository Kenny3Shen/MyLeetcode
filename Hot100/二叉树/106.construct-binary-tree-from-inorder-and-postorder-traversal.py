#
# @lc app=leetcode.cn id=106 lang=python3
# @lcpr version=30204
#
# [106] 从中序与后序遍历序列构造二叉树
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
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # postorder的最后一个节点是根节点
        # 在inorder中找到根节点的位置，左边是左子树，右边是右子树
        # 递归处理左右子树
        if not inorder:
            return None
        left_size = inorder.index(postorder[-1])
        left = self.buildTree(inorder[:left_size], postorder[:left_size])
        right = self.buildTree(inorder[left_size+1:], postorder[left_size:-1])
        return TreeNode(postorder[-1], left, right)
# @lc code=end



#
# @lcpr case=start
# [9,3,15,20,7]\n[9,15,7,20,3]\n
# @lcpr case=end

# @lcpr case=start
# [-1]\n[-1]\n
# @lcpr case=end

#

