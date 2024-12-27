/* 实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：
任意一个节点，其两棵子树的高度差不超过 1。


示例 1:
给定二叉树 [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7
返回 true 。
示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]
      1
     / \
    2   2
   / \
  3   3
 / \
4   4
返回 false 。
 */
#include <cmath>
#include <algorithm>
using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int depth(TreeNode *root) //计算以root为根节点的子树的最大深度
    {
        if (!root)
            return 0;
        /*  int left = depth(root->left);
        int right = depth(root->right);*/
        return max(depth(root->left), depth(root->right)) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        //如果根节点的左右子树高度差小于2
        return abs(depth(root->left) - depth(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right); //继续递归判断左孩子右孩子
    }
};