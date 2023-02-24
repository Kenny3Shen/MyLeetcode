/* 给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，
创建一棵高度最小的二叉搜索树。

示例:
给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

          0 
         / \ 
       -3   9 
       /   / 
     -10  5 
 */

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <vector>
using namespace std;
class Solution
{
public:
    TreeNode *dfs(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return nullptr;
        int mid = (l + r + 1) >> 1; // +1 可省略，最小高度树不唯一
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(nums, l, mid - 1);
        root->right = dfs(nums, mid + 1, r);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return dfs(nums, 0, nums.size() - 1);   //nums是有序数组
    }
};

