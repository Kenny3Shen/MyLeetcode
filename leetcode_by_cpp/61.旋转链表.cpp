/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (40.50%)
 * Likes:    362
 * Dislikes: 0
 * Total Accepted:    94.8K
 * Total Submissions: 234.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
 * 
 */
#include "leetcode.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if(!head)
            return nullptr;
        int reverseK = 0;
        ListNode *t = head;
        while (t)
        {
            reverseK++;
            t = t->next;
        }
        reverseK = k % reverseK;
        if (!reverseK)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (reverseK--)
            fast = fast->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* res = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return res;
    }
};
// @lc code=end
