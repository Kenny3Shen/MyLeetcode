/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (70.39%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    31.5K
 * Total Submissions: 44.7K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，找到其最大深度。
 * 
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 我们应返回其最大深度，3。
 * 
 * 说明:
 * 
 * 
 * 树的深度不会超过 1000。
 * 树的节点总不会超过 5000。
 * 
 */

// @lc code=start

// Definition for a Node.
/* class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
 */
#include <queue>
using namespace std;
class Solution
{
public:
    /* int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        queue<pair<Node *, int>> que;
        int level = 0;
        que.push(make_pair(root, 1));
        while (!que.empty())
        {
            auto node = que.front().first;
            level = que.front().second;
            que.pop();
            if (!node->children.empty())
                for (auto n : node->children)
                    que.push(make_pair(n, level + 1));
        }
        return level;
    } */
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int m = 0;
        for (Node * n : root->children)
            m = max(m, maxDepth(n));
        return ++m;
    }
};
// @lc code=end
