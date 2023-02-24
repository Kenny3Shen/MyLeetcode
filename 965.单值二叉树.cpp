/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
 */

// @lc code=start
#include <stack>
using namespace std;
//Definition for a binary tree node.
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
    bool isUnivalTree(TreeNode *root)
    {
        stack<TreeNode *> st;
        int unival = root->val;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            if (node)
            {
                st.pop(); //先弹出避免重复操作
                if (node->right)
                    st.push(node->right);

                st.push(node); //添加中节点
                st.push(nullptr);

                if (node->left)
                    st.push(node->left);
            }
            else
            {
                st.pop();        //空节点弹出
                node = st.top(); //取栈元素
                st.pop();
                if (node->val != unival) //比较
                    return false;
            }
        }
        return true;
    }
};

//inorder -> stack.push(right, mid, left) -> stack.pop(left, mid, right)
//preorder -> stack.push(right, left, mid) -> stack.pop(mid, left, right)
//inorder -> stack.push(mid, right, left) -> stack.pop(left, right, mid)
// @lc code=end
