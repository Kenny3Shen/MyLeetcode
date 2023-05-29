/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 *
 * https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (56.81%)
 * Likes:    183
 * Dislikes: 0
 * Total Accepted:    22.5K
 * Total Submissions: 39.6K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 * 
 * 案例 1:
 * 
 * 
 * 输入: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * 输出: True
 * 
 * 
 * 
 * 
 * 案例 2:
 * 
 * 
 * 输入: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * 输出: False
 * 
 * 
 * 
 * 
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    vector<int> v;
    unordered_map<int, int> map;

public:
    void traversal(TreeNode *root)
    {
        if (!root)
            return;
        traversal(root->left);
        v.push_back(root->val);
        traversal(root->right);
    }
    bool findTarget(TreeNode *root, int target)
    {
        traversal(root);
        /* for (int i = 0; i < v.size(); i++)
        {
            if (map.find(target - v[i]) != map.end())
            {
                return true;
            }
            map[v[i]] = i;
        }
        return false; */
        int left = 0, right = v.size() - 1;
        while (left < right)
        {
            int curSum = v[left] + v[right];
            if (curSum == target)
                return true;
            else if (curSum < target)
                left++;
            else
                right--;
        }
        return false;
    }
};
// @lc code=end
