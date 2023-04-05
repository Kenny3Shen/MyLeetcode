/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 *
 * https://leetcode.cn/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (67.40%)
 * Likes:    507
 * Dislikes: 0
 * Total Accepted:    84.1K
 * Total Submissions: 124.7K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * 树可以看成是一个连通且 无环 的 无向 图。
 *
 * 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n
 * 中间，且这条附加的边不属于树中已存在的边。图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai
 * 和 bi 之间存在一条边。
 *
 * 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: edges = [[1,2], [1,3], [2,3]]
 * 输出: [2,3]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
 * 输出: [1,4]
 *
 *
 *
 *
 * 提示:
 *
 *
 * n == edges.length
 * 3
 * edges[i].length == 2
 * 1
 * ai != bi
 * edges 中无重复元素
 * 给定的图是连通的 
 *
 *
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    // 树是有n - 1条边的有向无环图
    int Find(vector<int> &parent, int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = Find(parent, parent[x]);
    }
    void Union(vector<int> &parent, int x, int y)
    {
        int xRoot = Find(parent, x), yRoot = Find(parent, y);
        if (xRoot != yRoot)
            parent[yRoot] = xRoot;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        for (auto edge : edges)
        {
            if (Find(parent, edge[0]) == Find(parent, edge[1]))
                return edge;
            Union(parent, edge[0], edge[1]);
        }
        return {0, 0};
    }
};
// @lc code=end
