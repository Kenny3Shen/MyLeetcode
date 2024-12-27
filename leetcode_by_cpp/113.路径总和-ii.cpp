/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (60.95%)
 * Likes:    318
 * Dislikes: 0
 * Total Accepted:    74.1K
 * Total Submissions: 121.5K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
//* Definition for a binary tree node.
/* struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; */

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

public:
    void traversal(TreeNode *root, int sum)
    {
        if (!root->left && !root->right && !sum) //叶子节点且和为sum
        {
            res.push_back(path);
            return;
        }
        if (!root->left && !root->right) // 遇到叶子节点而没有找到合适的边，直接返回
            return;
        if (root->left) // 左 （空节点不遍历）
        {
            path.push_back(root->left->val);
            //sum -= root->left->val;
            traversal(root->left, sum - root->left->val); // 递归
            //sum += root->left->val;     //  这个回溯其实隐含在了 traversal(root->left, sum - root->left->val)
            path.pop_back(); // 回溯
        }
        if (root->right) // 右 （空节点不遍历）
        {
            path.push_back(root->right->val);
            //sum -= root->right->val;
            traversal(root->right, sum - root->right->val); // 递归
            //sum += root->right->val;     // 这个回溯其实隐含在了 traversal(root->right, sum - root->right->val)
            path.pop_back(); // 回溯
        }
    }
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (!root)
            return res;
        path.push_back(root->val);
        traversal(root, sum - root->val);
        return res;
    }
};
// @lc code=end
