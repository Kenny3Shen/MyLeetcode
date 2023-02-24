/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (66.64%)
 * Likes:    365
 * Dislikes: 0
 * Total Accepted:    166.3K
 * Total Submissions: 248.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [1,2,3]
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
#include <vector>
#include <stack>
using namespace std;
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
class Solution
{
private:
    vector<int> res;

public:
    void preOrder(TreeNode *root)
    {
        if (!root)
            return;
        res.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        /* if (!root)
            return res;
        preOrder(root);
        return res; */
        stack<TreeNode* > s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();
            if(cur)
                res.push_back(cur->val);
            else
                continue;
            s.push(cur->right);
            s.push(cur->left);
        }
        return res;
        
    }
};
// @lc code=end
