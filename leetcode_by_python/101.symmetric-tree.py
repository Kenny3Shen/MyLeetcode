#
# @lc app=leetcode.cn id=101 lang=python3
# @lcpr version=30204
#
# [101] 对称二叉树
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isMirror(self, l, r):
        if not l and not r:
            return True
        if not l or not r:
            return False
        return (
            l.val == r.val
            and self.isMirror(l.left, r.right)
            and self.isMirror(l.right, r.left)
        )

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        return self.isMirror(root.left, root.right)


# @lc code=end


#
# @lcpr case=start
# [1,2,2,3,4,4,3]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,2,null,3,null,3]\n
# @lcpr case=end

#
