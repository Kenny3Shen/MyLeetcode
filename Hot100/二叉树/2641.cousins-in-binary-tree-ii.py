#
# @lc app=leetcode.cn id=2641 lang=python3
# @lcpr version=30204
#
# [2641] 二叉树的堂兄弟节点 II
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
    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        dummy = TreeNode(0, root)
        # (node, val, parent)
        q = deque([(root, root.val, dummy)])
        while q:
            n = len(q)
            nodes = []
            sum_level = 0 
            for _ in range(n):
                node, val, parent = q.popleft()
                nodes.append((node, val, parent))
                sum_level += val
        
            # {parent: child_sum}
            child_sum = defaultdict(int)
            for node, val, parent in nodes:
                child_sum[parent] += val

            for node, val, parent in nodes:
                # 堂兄弟节点和 = 层和 - 当前节点的父节点的儿子和
                node.val = sum_level - child_sum[parent]
                if node.left:
                    q.append((node.left, node.left.val, node))
                if node.right:
                    q.append((node.right, node.right.val, node))
        return dummy.left
                    


# @lc code=end



#
# @lcpr case=start
# [5,4,9,1,10,null,7]\n
# @lcpr case=end

# @lcpr case=start
# [3,1,2]\n
# @lcpr case=end

#

