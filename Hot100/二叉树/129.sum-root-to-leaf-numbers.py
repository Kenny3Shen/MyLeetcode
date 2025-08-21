#
# @lc app=leetcode.cn id=129 lang=python3
# @lcpr version=30204
#
# [129] 求根节点到叶节点数字之和
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
    def sumNumbers(self, root: Optional[TreeNode], t: int = 0) -> int:
        if not root:
            return 0
        t = t * 10 + root.val
        if not root.left and not root.right:
            return t
        left_sum = self.sumNumbers(root.left, t)
        right_sum = self.sumNumbers(root.right, t)
        return left_sum + right_sum
# @lc code=end



#
# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

# @lcpr case=start
# [4,9,0,5,1]\n
# @lcpr case=end

#

