#include <bits/stdc++.h>
#define ll long long
using namespace std;
using PII = pair<int, int>;
#ifndef __MY_LEETCODE__ // guard防卫式声明
#define __MY_LEETCODE__

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
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

// priority_queue<int, vector<int>, less<int>> pq; 默认大根堆，每次弹出最大值

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
        return parent[x] == x ? x : parent[x] = Find(parent[x]);
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

/* void select_sort(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
} */

/* void bubble_sort(vector<int> &nums)
{
    bool flag = true;
    for (int i = nums.size() - 1; flag && i > 0; i--)
    {
        flag = false;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
    }
} */

/* void quick_sort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int l = left, r = right;
        int pivot = nums[left];
        while (l < r)
        {
            while (l < r && nums[r] >= pivot)
                r--;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pivot)
                l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        quick_sort(nums, left, l - 1);
        quick_sort(nums, l + 1, right);
    }
} */