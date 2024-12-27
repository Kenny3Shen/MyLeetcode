/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 *
 * https://leetcode-cn.com/problems/construct-string-from-binary-tree/description/
 *
 * algorithms
 * Easy (55.66%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 39.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
 * 
 * 空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 二叉树: [1,2,3,4]
 * ⁠      1
 * ⁠    /   \
 * ⁠   2     3
 * ⁠  /    
 * ⁠ 4     
 * 
 * 输出: "1(2(4))(3)"
 * 
 * 解释: 原本将是“1(2(4)())(3())”，
 * 在你省略所有不必要的空括号对之后，
 * 它将是“1(2(4))(3)”。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 二叉树: [1,2,3,null,4]
 * ⁠      1
 * ⁠    /   \
 * ⁠   2     3
 * ⁠    \  
 * ⁠     4 
 * 
 * 输出: "1(2()(4))(3)"
 * 
 * 解释: 和第一个示例相似，
 * 除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start

//Definition for a binary tree node.
/* struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 */
class Solution
{
public:
    string res = "";
    void preOrder(TreeNode *root)
    {
        if (!root)
            return;
        res.append(to_string(root->val));
        //当其左孩子或右孩子不为空时，不管当前的根节点是否为空都要输出左孩子的值
        if (root->left || root->right)
        {
            //左孩子不可忽略
            res.push_back('(');
            preOrder(root->left);
            res.push_back(')');
            //右孩子可忽略
            if (root->right)
            {
                res.push_back('(');
                preOrder(root->right);
                res.push_back(')');
            }
        }
    }
    string tree2str(TreeNode *t)
    {
        preOrder(t);
        return res;
    }
};
// @lc code=end
