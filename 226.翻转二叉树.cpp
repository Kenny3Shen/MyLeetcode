
/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 *
 * https://leetcode-cn.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (75.18%)
 * Likes:    531
 * Dislikes: 0
 * Total Accepted:    104.2K
 * Total Submissions: 136.9K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * 翻转一棵二叉树。
 * 
 * 示例：
 * 
 * 输入：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * 输出：
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * 备注:
 * 这个问题是受到 Max Howell 的 原问题 启发的 ：
 * 
 * 谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。
 * 
 */

// @lc code=start

// Definition for a binary tree node.
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
/* struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; */

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        /* if (!root)
            return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root; */

        /* stack<TreeNode *> st;
        if (root)
            st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node)
            {
                st.pop();
                if (node->right)
                    st.push(node->right); //right
                if (node->left)
                    st.push(node->left); //left

                st.push(node); //mid
                st.push(NULL);
            }
            else
            {
                st.pop(); //NULL push
                node = st.top();
                st.pop();
                swap(node->left, node->right);
            }
        }
        return root; */

        queue<TreeNode *> que;
        if (root)
            que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            while (size--)
            {
                TreeNode *node = que.front();
                que.pop();
                swap(node->left, node->right); // 节点处理 mid
                if (node->left)
                    que.push(node->left); //left
                if (node->right)
                    que.push(node->right); //right
            }
        }
        return root;
    }
};
// @lc code=end
