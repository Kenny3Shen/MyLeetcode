/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
#include <vector>
using namespace std;
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
private:
    TreeNode *traversal(vector<int> nums, int left, int right)
    {
        if (left >= right) //遇到空节点，也就是数组区间为 0
            return nullptr; //左闭右开原则
        //求分隔点下标
        int maxValueIndex = left;
        for (int i = left + 1; i < right; i++)
            if (nums[i] > nums[maxValueIndex])
                maxValueIndex = i;

        TreeNode *root = new TreeNode(nums[maxValueIndex]);

        // 左闭右开：[left, maxValueIndex)
        root->left = traversal(nums, left, maxValueIndex);
        // 左闭右开：[maxValueIndex + 1, right)
        root->right = traversal(nums, maxValueIndex + 1, right);

        return root;
    }

public: 
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return traversal(nums, 0, nums.size()); //左闭右开原则
    }
};
//一般情况来说：如果让空节点（空指针）进入递归，就不加if
//如果不让空节点进入递归，就加if限制一下， 终止条件也会相应的调整。
// @lc code=end
