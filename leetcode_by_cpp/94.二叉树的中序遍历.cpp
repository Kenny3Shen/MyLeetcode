/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (72.64%)
 * Likes:    670
 * Dislikes: 0
 * Total Accepted:    235.3K
 * Total Submissions: 323.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
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
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */
#include <vector>
#include <stack>
using namespace std;
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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        if (root != NULL)
            st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node != NULL)
            {
                st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right)
                    st.push(node->right); // 添加右节点

                st.push(node); // 添加中节点
                st.push(NULL); // 中节点访问过，但是还没有处理，需要做一下标记。

                if (node->left)
                    st.push(node->left); // 添加左节点
            }
            else
            {
                st.pop();        // 将空节点弹出
                node = st.top(); // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入到数组中
            }
        }
        return result;
    }
};
// @lc code=end
