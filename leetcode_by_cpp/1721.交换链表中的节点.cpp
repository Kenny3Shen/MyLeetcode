/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 *
 * [1721] 交换链表中的节点
 */

// @lc code=start
//Definition for singly-linked list.
/* struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */

class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        /* int size = 0;
        ListNode *temp = dummyNode;
        while (temp)
        {
            temp = temp->next;
            size++;
        } */
        ListNode *first = dummyNode;
        ListNode *last = dummyNode;
        int t = 0;
        while (dummyNode) //下标从0开始，走 K 步 first 到第 K 个节点
        {
            if (t < k)
                first = first->next;
            else //此时last开始走，当 node 为 null 时，last 差 k 步到最后的 null(即倒数第 k个)
                last = last->next;

            t++;
            dummyNode = dummyNode->next;
        }
        /* 
        while (t--)
            first = first->next;
        t = size - k;
        while (t--)
            last = last->next; */

        int s = first->val;
        first->val = last->val;
        last->val = s;

        return head;
    }
};
// @lc code=end
