/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 *
 * https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (46.82%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    17.9K
 * Total Submissions: 38.2K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或
 * 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。
 * 
 * 更正式地说，root.val = min(root.left.val, root.right.val) 总成立。
 * 
 * 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [2,2,5,null,null,5,7]
 * 输出：5
 * 解释：最小的值是 2 ，第二小的值是 5 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [2,2,2]
 * 输出：-1
 * 解释：最小的值是 2, 但是不存在第二小的值。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 25] 内
 * 1 
 * 对于树中每个节点 root.val == min(root.left.val, root.right.val)
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int findSecondMinimumValue(TreeNode *root)
    {
        if (!root || !root->left || !root->right)
            return -1; //空节点或不满足题意

        int left = root->left->val, right = root->right->val;

        //若根节点和左节点值相同，则递归找左子树的第二小节点
        if (root->val == root->left->val)
            left = findSecondMinimumValue(root->left);
        //若根节点和右节点值相同，则递归找右子树的第二小节点
        if (root->val == root->right->val)
            right = findSecondMinimumValue(root->right);

        //若根节点等于左右子树的第二小节点返回-1
        if (root->val == left && root->val == right)
            return -1;

        //根据当前的根、左右节点的值继续判断
        int min_lr = min(left, right);
        if (root->val < min_lr)
            return min_lr; //根节点小于最小值，返回最小值
        else
            return max(left, right); //根节点等于最小值，返回最大值
    }
};
// @lc code=end
