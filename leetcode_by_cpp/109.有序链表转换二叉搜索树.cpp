/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (73.35%)
 * Likes:    277
 * Dislikes: 0
 * Total Accepted:    37.2K
 * Total Submissions: 50.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
using namespace std;
class Solution
{
public:
    TreeNode *DFS(vector<int> &nums, int start, int end)
    {
        if (start == end)
        {
            return NULL;
        }
        int mid = (start + end) >> 1;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = DFS(nums, start, mid);
        root->right = DFS(nums, mid + 1, end);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        /* vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return DFS(nums, 0, nums.size()); */

        return buildTree(head, nullptr);
    }

    TreeNode *buildTree(ListNode *head, ListNode *tail)
    {
        if (head == tail)
            return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = buildTree(head, slow);
        root->right = buildTree(slow->next, tail);
        return root;
    }
};
// @lc code=end
