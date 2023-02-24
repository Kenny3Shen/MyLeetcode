#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <bitset>
#include <regex>
using namespace std; // It is vital that never use "using namespace" in head file.
using ll = long long;
using PII = pair<int, int>;
#ifndef __MY_LEETCODE__ // guard防卫式声明
#define __MY_LEETCODE__

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

/* class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;
    int mergeCount = 0;

public:
    UnionFind(int n) : parent(vector<int>(n)), rank(vector<int>(n, 1))
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    };

    ~UnionFind();

    int Find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y)
    {
        int xRoot = Find(x), yRoot = Find(y);
        if (xRoot != yRoot)
        {
            // parent[yRoot] = xRoot;
            mergeCount++;                   // 只有不属于一个集合时，合并才次数加1
            if (rank[yRoot] <= rank[xRoot])
                parent[yRoot] = xRoot;      // yRoot挂到xRoot上
            else
                parent[xRoot] = yRoot;      // xRoot挂到yRoot上
            if (rank[yRoot] == rank[xRoot])
                rank[xRoot]++;              // 秩相同时才加1
        }
    }
}; */
