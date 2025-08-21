#
# @lc app=leetcode.cn id=1448 lang=python3
# @lcpr version=30204
#
# [1448] 统计二叉树中好节点的数目
#

from lc import *

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
    def goodNodes(self, root: Optional[TreeNode], pre_val: int = -inf) -> int:
        if not root:
            return 0
        left_good = self.goodNodes(root.left, max(pre_val, root.val))
        right_good = self.goodNodes(root.right, max(pre_val, root.val))
        return left_good + right_good + (root.val >= pre_val)
            


# @lc code=end


#
# @lcpr case=start
# [3,1,4,3,null,1,5]\n
# @lcpr case=end

# @lcpr case=start
# [3,3,null,4,2]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#
