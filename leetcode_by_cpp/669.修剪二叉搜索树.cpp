/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 */

// @lc code=start

//Definition for a binary tree node.
/* struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; */

class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        /* if (root == nullptr)
            return nullptr;
        if (root->val < low)
        {
            TreeNode *right = trimBST(root->right, low, high); // 寻找符合区间[low, high]的节点
            return right;
        }
        if (root->val > high)
        {
            TreeNode *left = trimBST(root->left, low, high); // 寻找符合区间[low, high]的节点
            return left;
        }
        root->left = trimBST(root->left, low, high);   // root->left接入符合条件的左孩子
        root->right = trimBST(root->right, low, high); // root->right接入符合条件的右孩子
        return root; */

        if (!root)
            return nullptr;

        // 处理头结点，让root移动到[L, R] 范围内，注意是左闭右闭
        while (root->val < low || root->val > high)
        {
            if (root->val < low)
                root = root->right; // 小于L往右走
            else
                root = root->left; // 大于R往左走
        }
        TreeNode *cur = root;
        // 此时root已经在[L, R] 范围内，处理左孩子元素小于L的情况
        while (cur != nullptr)
        {
            while (cur->left && cur->left->val < low)
            {
                cur->left = cur->left->right;
            }
            cur = cur->left;
        }
        cur = root;

        // 此时root已经在[L, R] 范围内，处理右孩子大于R的情况
        while (cur != nullptr)
        {
            while (cur->right && cur->right->val > high)
            {
                cur->right = cur->right->left;
            }
            cur = cur->right;
        }
        return root;
    }
};
// @lc code=end
