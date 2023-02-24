/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (44.60%)
 * Likes:    386
 * Dislikes: 0
 * Total Accepted:    79.2K
 * Total Submissions: 174.2K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start

//Definition for singly-linked list.
/* struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}; */

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *p = dummyNode;
        ListNode *del = nullptr;
        while (p->next)
        {
            if (p->next->val == val)
            {
                del = p->next;
                p->next = p->next->next;
                delete del;
            }
            else
                p = p->next;
        }
        return dummyNode->next;
        /*if (!head)
            return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head; */
    }
};
// @lc code=end
