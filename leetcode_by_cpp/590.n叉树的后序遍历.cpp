/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (73.55%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    31.6K
 * Total Submissions: 42.6K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的后序遍历。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其后序遍历: [5,6,3,2,4,1].
 * 
 * 
 * 
 * 说明: 递归法很简单，你可以使用迭代法完成此题吗?
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> ans;
    vector<int> postorder(Node *root)
    {
        /* if(!root)
            return ans;
        for(auto i : root->children)
            postorder(i);
        ans.push_back(root->val);
        return ans; */

        vector<int> res;
        if (!root)
            return res;
        stack<Node *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            Node *tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            for (auto i : tmp->children)
            {
                stk.push(i);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
