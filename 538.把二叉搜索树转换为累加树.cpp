/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (63.28%)
 * Likes:    328
 * Dislikes: 0
 * Total Accepted:    39.3K
 * Total Submissions: 62.1K
 * Testcase Example:  '[5,2,13]'
 *
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
 * Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 * 
 * 
 * 
 * 例如：
 * 
 * 输入: 原始二叉搜索树:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * 输出: 转换为累加树:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 * 
 * 
 * 
 * 
 * 注意：本题和 1038:
 * https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同
 * 
 */
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
}; */

//从树中可以看出累加的顺序是右中左
//所以我们需要反中序遍历这个二叉树，然后顺序累加就可以了
class Solution
{
private:
    int pre; // 记录前一个节点的数值
    void traversal(TreeNode *cur)
    {
        if (cur == NULL)
            return;
        traversal(cur->right); //反中序遍历
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);

    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        pre = 0;
        traversal(root);
        return root;
    }
};
// @lc code=end
