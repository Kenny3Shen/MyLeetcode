#
# @lc app=leetcode.cn id=230 lang=python3
# @lcpr version=30204
#
# [230] 二叉搜索树中第 K 小的元素
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
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        cnt = 0
        ans = -1
        def dfs(node):
            nonlocal cnt, ans
            if not node:
                return
            dfs(node.left)
            if ans != -1:
                return
            cnt += 1
            if cnt == k:
                ans = node.val
                return
            dfs(node.right)
        
        dfs(root)  
        return ans 
        # a = []
        # def dfs(node):
        #     if not node:
        #         return
        #     dfs(node.left)
        #     a.append(node.val)
        #     dfs(node.right)
        # dfs(root)
        # return a[k-1]
# @lc code=end



#
# @lcpr case=start
# [3,1,4,null,2]\n1\n
# @lcpr case=end

# @lcpr case=start
# [5,3,6,2,4,null,null,1]\n3\n
# @lcpr case=end

#

