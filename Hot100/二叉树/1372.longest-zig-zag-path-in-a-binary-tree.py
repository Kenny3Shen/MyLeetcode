#
# @lc app=leetcode.cn id=1372 lang=python3
# @lcpr version=30204
#
# [1372] 二叉树中的最长交错路径
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
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def dfs(node, is_left, length):
            nonlocal ans
            if not node:
                return
            ans = max(ans, length)
            if is_left:
                # 上次是左边，尝试右边
                dfs(node.left, False, length + 1)
                # 重置长度，尝试左边
                dfs(node.right, True, 1)
            else:
                dfs(node.right, True, length + 1)
                dfs(node.left, False, 1)
        dfs(root, True, 0)
        dfs(root, False, 0)
        return ans
# @lc code=end



#
# @lcpr case=start
# [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]\n
# @lcpr case=end

# @lcpr case=start
# [1,1,1,null,1,null,null,1,1,null,1]\n
# @lcpr case=end

# @lcpr case=start
# [1]\n
# @lcpr case=end

#

