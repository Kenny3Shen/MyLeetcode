#
# @lc app=leetcode.cn id=133 lang=python3
# @lcpr version=30204
#
# [133] 克隆图
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""
from collections import deque
from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
            
        # 使用字典存储已访问的节点
        visited = {}
        
        # BFS 复制图
        def bfs(node):
            if not node:
                return None
                
            # 创建第一个节点
            visited[node] = Node(node.val, [])
            queue = deque([node])
            
            while queue:
                curr = queue.popleft()
                # 处理所有邻居
                for neighbor in curr.neighbors:
                    if neighbor not in visited:
                        # 创建新节点并加入队列
                        visited[neighbor] = Node(neighbor.val, [])
                        queue.append(neighbor)
                    # 添加到当前节点的邻居列表
                    visited[curr].neighbors.append(visited[neighbor])
            
            return visited[node]
            
        return bfs(node)
# @lc code=end



#
# @lcpr case=start
# [[2,4],[1,3],[2,4],[1,3]]\n
# @lcpr case=end

# @lcpr case=start
# [[]]\n
# @lcpr case=end

# @lcpr case=start
# []\n
# @lcpr case=end

#

