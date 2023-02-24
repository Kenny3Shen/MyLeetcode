/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start

//Definition for singly-linked list.
/* struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *h1 = new ListNode(0); // 记录比x小的节点组成的链表
        ListNode *h2 = new ListNode(0); // 记录比x大的节点组成的链表
        ListNode *p1 = h1, *p2 = h2;    //dummyNode,控制两个链表的头节点
        while (head)
        {
            if (head->val < x)
            {
                p1->next = head;
                p1 = p1->next;
            }
            else
            {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        // merge two list
        p2->next = nullptr;  //大链表最后置空
        p1->next = h2->next; //大链表接到小链表后面
        return h1->next;
    }
};
// @lc code=end
