/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (39.31%)
 * Likes:    982
 * Dislikes: 0
 * Total Accepted:    229.9K
 * Total Submissions: 583.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
 * 
 */

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *header = new ListNode(0); //定义虚拟头节点，来保证可以删除头节点
        header->next = head;
        ListNode *p = header; //不能直接赋值为head,因为可能会删除头结点
        ListNode *q = header;
        while (n--)
            p = p->next; //pre指针领先tail指针n个位置
        while (p->next)
        {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next; //删除倒数第 n 个元素
        return header->next;
    }
};
// @lc code=end
