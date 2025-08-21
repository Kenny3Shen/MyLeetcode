#
# @lc app=leetcode.cn id=199 lang=python3
# @lcpr version=30204
#
# [199] 二叉树的右视图
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
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # ans = []
        # def dfs(node, depth):
        #     if not node:
        #         return
        #     if len(ans) == depth:
        #         ans.append(node.val)
        #     dfs(node.right, depth + 1)
        #     dfs(node.left, depth + 1)
        # dfs(root, 0)
        # return ans
        if not root:
            return []
        ans = []
        q = deque([root])
        while q:
            for i in range(len(q)):
                node = q.popleft()
                if i == 0:
                    ans.append(node.val)
                if node.right:
                    q.append(node.right)
                if node.left:
                    q.append(node.left)
        return ans
# @lc code=end



#
# @lcpr case=start
# [1,2,3,null,5,null,4]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3,4,null,null,null,5]\n
# @lcpr case=end

# @lcpr case=start
# [1,null,3]\n
# @lcpr case=end

# @lcpr case=start
# []\n
# @lcpr case=end

#

