/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (33.58%)
 * Likes:    933
 * Dislikes: 0
 * Total Accepted:    224.6K
 * Total Submissions: 668.8K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <stack>
using namespace std;
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
    long long val = LONG_LONG_MIN;

public:
    bool isValidBST(TreeNode *root)
    {
        /* if (!root)
            return true;

        bool left = isValidBST(root->left); //left

        if (val < root->val)
            val = root->val; //mid
        else
            return false;

        bool right = isValidBST(root->right); // right
        return left && right; */
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = NULL; // 记录前一个节点
        while (cur != NULL || !st.empty())
        {
            if (cur != NULL)
            {
                st.push(cur);
                cur = cur->left; // 左
            }
            else
            {
                cur = st.top(); // 中
                st.pop();
                if (pre != NULL && cur->val <= pre->val)
                    return false;
                pre = cur; //保存前一个访问的结点

                cur = cur->right; // 右
            }
        }
        return true;
    }
};
// @lc code=end
