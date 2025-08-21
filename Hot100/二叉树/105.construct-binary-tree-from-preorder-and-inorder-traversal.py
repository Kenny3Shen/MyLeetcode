#
# @lc app=leetcode.cn id=105 lang=python3
# @lcpr version=30204
#
# [105] 从前序与中序遍历序列构造二叉树
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
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # 前序遍历的第一个节点是根节点
        # 中序遍历中根节点左边是左子树，右边是右子树
        # [1:1+root_index]是左子树的前序遍历，[:root_index]是左子树的中序遍历
        # [1+root_index:]是右子树的前序遍历，[root_index+1:]是右子树的中序遍历
        if not preorder:
            return None
        root_index = inorder.index(preorder[0])
        left = self.buildTree(preorder[1:1+root_index], inorder[:root_index])
        right = self.buildTree(preorder[1+root_index:], inorder[root_index+1:])
        return TreeNode(preorder[0], left, right)
# @lc code=end



#
# @lcpr case=start
# [3,9,20,15,7]\n[9,3,15,20,7]\n
# @lcpr case=end

# @lcpr case=start
# [-1]\n[-1]\n
# @lcpr case=end

#

