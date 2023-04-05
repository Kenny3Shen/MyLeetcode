/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (38.18%)
 * Likes:    4995
 * Dislikes: 0
 * Total Accepted:    567.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */
#include <vector>
using namespace std;
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *sum = new ListNode();
        ListNode *p = sum;
        p->val = (l1->val + l2->val) % 10;
        int carry = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 && l2)
        {
            int temp = l1->val + l2->val + carry;
            ListNode *q = new ListNode(temp % 10);
            carry = temp / 10;
            p->next = q;
            p = q;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            int temp = l1->val + carry;
            ListNode *q = new ListNode(temp % 10);
            carry = temp / 10;
            p->next = q;
            p = q;
            l1 = l1->next;
        }

        while (l2)
        {
            int temp = l2->val + carry;
            ListNode *q = new ListNode(temp % 10);
            carry = temp / 10;
            p->next = q;
            p = q;
            l2 = l2->next;
        }

        if (carry)
        {
            ListNode *q = new ListNode(carry);
            p->next = q;
        }
        return sum;
    }
};
// @lc code=end
