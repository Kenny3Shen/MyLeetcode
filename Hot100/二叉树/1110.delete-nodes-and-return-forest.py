#
# @lc app=leetcode.cn id=1110 lang=python3
# @lcpr version=30204
#
# [1110] 删点成林
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
    def delNodes(
        self, root: Optional[TreeNode], to_delete: List[int]
    ) -> List[TreeNode]:
        s = set(to_delete)
        ans = []

        def dfs(node):
            if not node:
                return None
            node.left = dfs(node.left)
            node.right = dfs(node.right)
            if node.val not in s:
                return node
            if node.left:
                ans.append(node.left)
            if node.right:
                ans.append(node.right)
            return None

        if dfs(root):
            ans.append(root)
        return ans
# @lc code=end


#
# @lcpr case=start
# [1,2,3,4,5,6,7]\n[3,5]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,4,null,3]\n[3]\n
# @lcpr case=end

#
