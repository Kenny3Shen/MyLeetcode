/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (45.69%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    18.2K
 * Total Submissions: 39.9K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 
 * 假定 BST 有如下定义：
 * 
 * 
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 例如：
 * 给定 BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 返回[2].
 * 
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
 * 
 */
#include <vector>
using namespace std;
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
class Solution
{
public:
    void inOrder(TreeNode *root, vector<int> &v)
    {
        if (!root)
            return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> v;
        vector<int> res;
        if (!root)
            return v;
        inOrder(root, v);
        int cur = 1, max = 1;
        res.push_back(v[0]);               //初始化res数组
        for (int i = 1; i < v.size(); i++) //求数组v的众数
        {
            if (v[i] == v[i - 1])
                cur++;
            else
                cur = 1;
            
            if (cur == max)
                res.push_back(v[i]);
            else if (cur > max)
            {
                res.clear();
                max = cur;
                res.push_back(v[i]);
            }
        }
        return res;
    }
};
// @lc code=end
