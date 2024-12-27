/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (58.21%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    22.3K
 * Total Submissions: 38.2K
 * Testcase Example:  '[1,null,3,2]'
 *
 * 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * 输出：
 * 1
 * 
 * 解释：
 * 最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中至少有 2 个节点。
 * 本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
 * 相同
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start

// Definition for a binary tree node.
/* struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; */

class Solution
{
private:
    vector<int> v;

public:
    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        v.push_back(root->val); //BST中序遍历是有序序列
        inOrder(root->right);
    }

    int getMinimumDifference(TreeNode *root)
    {
        inOrder(root);
        int res =  v[1] - v[0];
        for (int i = 1; i < v.size() - 1; i++)
            res = min(res, v[i + 1] - v[i]);

        return res;
    }
};
// @lc code=end
