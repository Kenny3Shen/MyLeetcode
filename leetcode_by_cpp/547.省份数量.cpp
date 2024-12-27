/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */
#include "leetcode.h"
// @lc code=start

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) : parent(vector<int>(n)), rank(vector<int>(n, 1))
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y ,int &mergeCount)
    {
        int xRoot = Find(x), yRoot = Find(y);
        if(xRoot != yRoot) //直接合并
        {
            parent[yRoot] = xRoot;
            mergeCount++;
        }
        /* if (xRoot != yRoot) //按秩合并
        {
            mergeCount++;
            if (rank[yRoot] <= rank[xRoot])
                parent[yRoot] = xRoot;
            else
                parent[xRoot] = yRoot;
            if (rank[yRoot] == rank[xRoot])
                rank[xRoot]++;
        } */
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int mergeCount = 0;
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (isConnected[i][j] == 1)
                    uf.Union(i, j, mergeCount);

        return n - mergeCount;
    }
};

// @lc code=end
