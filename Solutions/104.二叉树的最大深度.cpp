/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (72.55%)
 * Likes:    490
 * Dislikes: 0
 * Total Accepted:    147.4K
 * Total Submissions: 202.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<queue>
class Solution {
public:
    int maxDepth(TreeNode* root) {
        //return (!root)? 0:max(maxDepth(root->left),maxDepth(root->right))+1;
        if (!root)  
            return 0;                     //判空
        queue<pair<TreeNode *, int>> que; //把节点和所在的层数绑定
        que.push(make_pair(root, 1));     //压入根节点，层数为1
        int level=0;
        while (!que.empty())
        {   //先保存头元素的内容
            TreeNode *node = que.front().first; //当前节点
            level = que.front().second;     //层数
            if (node->left)   //压入左节点
                que.push(make_pair(node->left, level + 1));
            if (node->right) //压入右节点
                que.push(make_pair(node->right, level + 1));
            que.pop();
        }
        return level;
    }
};
// @lc code=end

