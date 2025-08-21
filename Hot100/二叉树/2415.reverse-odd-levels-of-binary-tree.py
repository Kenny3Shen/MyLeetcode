#
# @lc app=leetcode.cn id=2415 lang=python3
# @lcpr version=30204
#
# [2415] 反转二叉树的奇数层
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
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        q = deque([root])
        level = 0
        while q:
            n = len(q)
            if level % 2 == 1:
                v = [node.val for node in q]
                v = v[::-1]
                for i in range(n):
                    q[i].val = v[i]
                    
            for _ in range(n):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            level += 1
        return root
        # if not root:
        #     return None
        
        # def dfs(left, right, level):
        #     if not left or not right:
        #         return
            
        #     # 如果是奇数层，交换节点值
        #     if level % 2 == 1:
        #         left.val, right.val = right.val, left.val
            
        #     # 递归处理子树，注意"交叉"递归以处理对称位置
        #     dfs(left.left, right.right, level + 1)
        #     dfs(left.right, right.left, level + 1)
        
        # # 从根节点的左右子节点开始处理
        # dfs(root.left, root.right, 1)
        # return root
# @lc code=end



#
# @lcpr case=start
# [2,3,5,8,13,21,34]\n
# @lcpr case=end

# @lcpr case=start
# [7,13,11]\n
# @lcpr case=end

# @lcpr case=start
# [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]\n
# @lcpr case=end

#

