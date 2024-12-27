/* 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：

给定的 k 保证是有效的。*/

///*  */ Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    int kthToLast(ListNode *head, int k)
    {
        /* vector<int> vec;
        while(head)
        {
            vec.push_back(head->val);
            head = head ->next;
        }
        return vec[vec.size() - k]; */
        ListNode *p = head, *q = head;
        while (k--)
        {
            p = p->next; //快指针 距离 慢指针 k个 节点
        }
        while (p) //p为尾节点，则q为倒数第k个节点
        {
            p = p->next;
            q = q->next;
        }
        return q->val;
    }
};