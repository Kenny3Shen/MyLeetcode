/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (52.18%)
 * Likes:    618
 * Dislikes: 0
 * Total Accepted:    94K
 * Total Submissions: 180.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 * 
 * 
 * 
 * 示例 :
 * 给定二叉树
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 * 
 * 
 * 
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
 * 
 */

// @lc code=start

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
    int maxNode = 0;
    int depth(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        maxNode = max(maxNode, left + right + 1);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return maxNode;
        maxNode = 1;
        depth(root);
        return maxNode - 1; // diameter = maxNode - 1
    }
};
// @lc code=end
