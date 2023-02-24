/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (55.38%)
 * Likes:    186
 * Dislikes: 0
 * Total Accepted:    33.8K
 * Total Submissions: 61K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 计算给定二叉树的所有左叶子之和。
 * 
 * 示例：
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
 * 
 * 
 */

// @lc code=start

/* struct TreeNode
{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; */
#include <queue>
using namespace std;
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> leftSum;
        int res = 0;
        leftSum.push(root);
        while (!leftSum.empty())    //BFS
        {
            auto head = leftSum.front();
            leftSum.pop();
            if (head->left)
            {
                if (!head->left->left && !head->left->right)
                    res += head->left->val;
                else
                    leftSum.push(head->left);
            }
            if (head->right)
                leftSum.push(head->right);
        }
        return res;

        /* if (!root)
            return 0;
        int res = 0;
        if (root->left) //DFS
        {
            if (!root->left->left && !root->left->right)
                res += root->left->val;
            else
                res += sumOfLeftLeaves(root->left);
        }
        if (root->right)
        {
            res += sumOfLeftLeaves(root->right);
        }
        return res; */
    }
};
// @lc code=end
