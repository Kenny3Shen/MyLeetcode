#
# @lc app=leetcode.cn id=2316 lang=python3
# @lcpr version=30204
#
# [2316] 统计无向图中无法互相到达点对数
#


# @lcpr-template-start
from typing import List
# @lcpr-template-end
# @lc code=start
class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        adj_list = [[] for _ in range(n)]
        visited = [False] * n
        for edge in edges:
            adj_list[edge[0]].append(edge[1])
            adj_list[edge[1]].append(edge[0])
        
        # 该连通分量的大小
        def dfs(node: int) -> int:
            visited[node] = True
            size = 1
            for neighbor in adj_list[node]:
                if not visited[neighbor]:
                    size += dfs(neighbor)
            return size
        
        res = 0
        visit_count = 0 # 已发现连通分量的节点数
        for node in range(n):
            if not visited[node]: # 新的连通分量
                size = dfs(node)
                res += size * visit_count
                visit_count += size
        return res
# @lc code=end



#
# @lcpr case=start
# 3\n[[0,1],[0,2],[1,2]]\n
# @lcpr case=end

# @lcpr case=start
# 7\n[[0,2],[0,5],[2,4],[1,6],[5,4]]\n
# @lcpr case=end

#

