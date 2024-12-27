/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 *
 * https://leetcode-cn.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (61.22%)
 * Likes:    729
 * Dislikes: 0
 * Total Accepted:    85.6K
 * Total Submissions: 139.8K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。
 * 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
 * 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
 * 
 * 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3,null,3,null,1]
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * 输出: 7 
 * 解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
 * 
 * 示例 2:
 * 
 * 输入: [3,4,5,1,3,null,1]
 * 
 * 3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * 输出: 9
 * 解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
 * 
 * 
 */

// @lc code=start
#include <unordered_map>
#include <vector>
using namespace std;
/* //Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; */

class Solution
{
public:
    unordered_map<TreeNode *, int> umap;
    int rob(TreeNode *root)
    {
        /*  if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->val;
        if (umap[root])
            return umap[root];
        int val1 = root->val; //rob father node
        if (root->left)
            val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            val1 += rob(root->right->left) + rob(root->right->right);

        //not rob father node
        int val2 = rob(root->left) + rob(root->right);
        umap[root] = max(val1, val2);
        return max(val1, val2); */

        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
    vector<int> robTree(TreeNode *root)
    {
        //0: not rob 1: rob 
        if (!root)
            return {0, 0};
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        //rob root
        int val1 = root->val + left[0] + right[0];

        //not rob root
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};
// @lc code=end
