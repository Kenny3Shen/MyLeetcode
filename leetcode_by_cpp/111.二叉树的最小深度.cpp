// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem111.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (41.78%)
 * Likes:    238
 * Dislikes: 0
 * Total Accepted:    64.8K
 * Total Submissions: 154.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
 * 
 */

// @lc code=start
//Definition for a binary tree node.
/* struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 */
#include <queue>
using namespace std;
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, int>> queue;
        queue.push(pair(root, 1));
        while (!queue.empty())  //BFS based on queue
        {
            TreeNode *curRoot = queue.front().first;
            int curLevel = queue.front().second;
            if (!curRoot->left && !curRoot->right)
                return curLevel;
            if (curRoot->left)
                queue.push(pair(curRoot->left, curLevel + 1));
            if (curRoot->right)
                queue.push(pair(curRoot->right, curLevel + 1));
            queue.pop();
        }
        return -1;
    }
};
// @lc code=end
