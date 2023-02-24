/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
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
#include <queue>
using namespace std;
class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        queue<TreeNode *> q;
        q.push(root);
        int flag = 2; //设置标签
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            { //在每一层遍历
                root = q.front();
                q.pop();
                if (root->left && root->right && ((root->left->val == x && root->right->val == y) || (root->left->val == y && root->right->val == x)))
                {
                    return false; //如果是亲兄弟，返回false
                }
                if (root->left)
                { //左孩子存在就入队，如果该结点值是x或y,标记值减一，说明找到一个；
                    q.push(root->left);
                    if (root->left->val == x || root->left->val == y)
                        flag--;
                }
                if (root->right)
                { //右孩子存在就入队，如果该结点值是x或y,标记值减一，说明找到一个；
                    q.push(root->right);
                    if (root->right->val == x || root->right->val == y)
                        flag--;
                }
            }
            if (flag == 1)
                return false; //该层只发现一个，说明x,y不在同一层，返回false
            if (flag == 0)
                return true; //x,y在同一层，且前面为亲兄弟的情况已经排除，所以是堂兄弟
        }                    //如果flag=2,说明不在该层，继续循环
        return false;
    }
};
// @lc code=end
