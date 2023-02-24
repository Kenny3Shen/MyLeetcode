/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (64.92%)
 * Likes:    316
 * Dislikes: 0
 * Total Accepted:    53.2K
 * Total Submissions: 81.8K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
private:
    vector<string> res;

public:
    void DFS(TreeNode *root, string path)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            path += to_string(root->val);
            res.push_back(path);
        }
        else
        {
            path = path + to_string(root->val) + "->";
            DFS(root->left, path);
            DFS(root->right, path);
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string path;
        DFS(root, path);
        return res;
    }
};
// @lc code=end
