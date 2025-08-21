#
# @lc app=leetcode.cn id=98 lang=python3
# @lcpr version=30204
#
# [98] 验证二叉搜索树
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
    pre = -inf
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # 前序遍历，需要记录上下界
        # def dfs(node, low, high):
        #     if not node:
        #         return True
        #     return low < node.val < high and dfs(node.left, low, node.val) and dfs(node.right, node.val, high)
        # return dfs(root, float('-inf'), float('inf'))

        # 中序遍历, 递增, 记录上一个节点的值
        
        if not root:
            return True
        if not self.isValidBST(root.left):
            return False
        if root.val <= self.pre:
            return False
        self.pre = root.val
        return self.isValidBST(root.right)


# @lc code=end



#
# @lcpr case=start
# [2,1,3]\n
# @lcpr case=end

# @lcpr case=start
# [5,1,4,null,null,3,6]\n
# @lcpr case=end

#

