/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (52.21%)
 * Likes:    677
 * Dislikes: 0
 * Total Accepted:    103.5K
 * Total Submissions: 197.9K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 * 
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
    ListNode *reverse(ListNode *head, int num)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *temp; //save cur->next
        while (num--)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        head->next = cur;
        return pre;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *pre = dummyNode;
        for (int i = 1; i < left; i++)
            pre = pre->next;

        pre->next = reverse(pre->next, right - left + 1);
        /* for(int i = left; i < right; i++)
        {
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        } */
        return dummyNode->next;
    }
};
// @lc code=end
