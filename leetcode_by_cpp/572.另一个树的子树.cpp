/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 */

// @lc code=start
#include <vector>
#include <queue>
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
public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s)
            return false;
        return isSubtree(s->left, t) || SameTree(s, t) || isSubtree(s->right, t);
    }

    bool SameTree(TreeNode *s, TreeNode *t)
    {
        if (s == nullptr && t == nullptr)
            return true;
        if (s == nullptr || t == nullptr)
            return false;
            
        return s->val == t->val && SameTree(s->left, t->left) && SameTree(s->right, t->right);
    }
};
// @lc code=end
