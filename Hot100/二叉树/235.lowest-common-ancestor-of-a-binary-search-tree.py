#
# @lc app=leetcode.cn id=235 lang=python3
# @lcpr version=30204
#
# [235] 二叉搜索树的最近公共祖先
#


# @lcpr-template-start
from lc import *
# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # p,q 都在root的右子树
        if p.val > root.val and q.val > root.val:
            return self.lowestCommonAncestor(root.right, p, q)
        # p,q 都在root的左子树
        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)
        # p,q 分别在root的左右子树 或者 其中一个是root
        return root
# @lc code=end



#
# @lcpr case=start
# [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
# @lcpr case=end

# @lcpr case=start
# [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
# @lcpr case=end

#

