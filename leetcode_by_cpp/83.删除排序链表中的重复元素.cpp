/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (49.62%)
 * Likes:    275
 * Dislikes: 0
 * Total Accepted:    85K
 * Total Submissions: 171.1K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */
#include "leetcode.h"
// @lc code=start

// Definition for singly-linked list.
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head) //如果所给链表为空直接返回，否则在执行ptr->next这部操作时会因为ptr为NULL而造成执行时错误
            return head;
        ListNode *p = head; //新建一个遍历指针
        while (p->next)
        {
            if (p->val == p->next->val)
            {
                ListNode *q = p->next;
                p->next = q->next;
                //delete q;
            }
            else
                p = p->next;
        }
        return head;
    }
};
// @lc code=end
