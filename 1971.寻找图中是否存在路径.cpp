/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 *
 * https://leetcode.cn/problems/find-if-path-exists-in-graph/description/
 *
 * algorithms
 * Easy (55.02%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    25.9K
 * Total Submissions: 47.1K
 * Testcase Example:  '3\n[[0,1],[1,2],[2,0]]\n0\n2'
 *
 * 有一个具有 n 个顶点的 双向 图，其中每个顶点标记从 0 到 n - 1（包含 0 和 n - 1）。图中的边用一个二维整数数组 edges
 * 表示，其中 edges[i] = [ui, vi] 表示顶点 ui 和顶点 vi 之间的双向边。 每个顶点对由 最多一条
 * 边连接，并且没有顶点存在与自身相连的边。
 *
 * 请你确定是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径 。
 *
 * 给你数组 edges 和整数 n、source 和 destination，如果从 source 到 destination 存在 有效路径 ，则返回
 * true，否则返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
 * 输出：true
 * 解释：存在由顶点 0 到顶点 2 的路径:
 * - 0 → 1 → 2
 * - 0 → 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination =
 * 5
 * 输出：false
 * 解释：不存在由顶点 0 到顶点 5 的路径.
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2 * 10^5
 * 0 <= edges.length <= 2 * 10^5
 * edges[i].length == 2
 * 0 <= ui, vi <= n - 1
 * ui != vi
 * 0 <= source, destination <= n - 1
 * 不存在重复边
 * 不存在指向顶点自身的边
 *
 *
 */
#include "leetcode.h"
// @lc code=start
class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) : parent(n), rank(n, 1)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int Find(int x)
    {
        return parent[x] == x ? x : parent[x] = Find(parent[x]);
    }

    void Union(int x, int y)
    {
        int xRoot = Find(x), yRoot = Find(y);
        if (xRoot != yRoot)
        {
            // parent[yRoot] = xRoot;   
            if (rank[yRoot] <= rank[xRoot])
                parent[yRoot] = xRoot; // yRoot挂到xRoot上
            else
                parent[xRoot] = yRoot; // xRoot挂到yRoot上
            if (rank[yRoot] == rank[xRoot])
                rank[xRoot]++; // 秩相同时才加1
        }
    }
};

class Solution
{
public:
    bool dfs(int source, int destination, vector<vector<int>> &adj, vector<bool> &visited)
    {
        if (source == destination)
            return true;
        visited[source] = true;
        for (int &next : adj[source])
            if (!visited[next] && dfs(next, destination, adj, visited))
                return true;
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        if(source == destination)
            return true;
        UnionFind uf(n);
        for(auto &e : edges)
            uf.Union(e[0], e[1]);
        return uf.Find(source) == uf.Find(destination);
        /* vector<bool> visited(n, false);
        vector<vector<int>> adjacent(n);
        for (auto &e : edges)
        {
            adjacent[e[0]].push_back(e[1]);
            adjacent[e[1]].push_back(e[0]);
        }
        return dfs(source, destination, adjacent, visited); */
        /* queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            if (vertex == destination)
                break;
            for (int &next : adjacent[vertex])
            {
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        return visited[destination]; */
    }
};
// @lc code=end
