/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.31%)
 * Likes:    392
 * Dislikes: 0
 * Total Accepted:    118.3K
 * Total Submissions: 163.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
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
private:
    vector<int> res;

public:
    void postOrder(TreeNode *root)
    {
        if (!root)
            return;
        postOrder(root->left);
        postOrder(root->right);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        /* if(!root)
            return res;
        postOrder(root);
        return res; */
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *cur = s.top();
            s.pop();
            if (cur)
                res.push_back(cur->val);
            else
                continue;
            s.push(cur->left);
            s.push(cur->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end
