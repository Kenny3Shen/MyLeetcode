/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (73.80%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    44.4K
 * Total Submissions: 60.1K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的前序遍历。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其前序遍历: [1,3,5,6,2,4]。
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
#include <stack>
using namespace std;
class Solution
{
private:
    vector<int> res;

public:
    void dfs(Node *root)
    {
        if (!root)
            return;
        res.push_back(root->val);
        for (auto n : root->children)
            dfs(n);
    }
    
    vector<int> preorder(Node *root)
    {
        /* if (!root)
            return res;
        dfs(root);
        return res; */

        if (!root)
            return res;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            auto temp = st.top();
            st.pop();
            res.push_back(temp->val);
            for (int i = temp->children.size() - 1; i >= 0; i--)
                st.push(temp->children[i]);
        }
        return res;
    }
};
// @lc code=end
