#
# @lc app=leetcode.cn id=508 lang=python3
# @lcpr version=30204
#
# [508] 出现次数最多的子树元素和
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
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        cnt = Counter()
        def dfs(node):
            if node is None:
                return 0
            s = node.val + dfs(node.left) + dfs(node.right)
            cnt[s] += 1
            return s
        dfs(root)
        max_cnt = max(cnt.values(), default=0)
        return [k for k, v in cnt.items() if v == max_cnt]
        
            
# @lc code=end



#
# @lcpr case=start
# [5,2,-3]\n
# @lcpr case=end

# @lcpr case=start
# [5,2,-5]\n
# @lcpr case=end

#

