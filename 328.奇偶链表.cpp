/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 *
 * https://leetcode-cn.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (63.60%)
 * Likes:    267
 * Dislikes: 0
 * Total Accepted:    62K
 * Total Submissions: 97.4K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * 
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 1->3->5->2->4->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2->1->3->5->6->4->7->NULL 
 * 输出: 2->3->6->7->1->5->4->NULL
 * 
 * 说明:
 * 
 * 
 * 应当保持奇数节点和偶数节点的相对顺序。
 * 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *even = head->next; //第一个偶数为链表的第二个结点
        ListNode *odd = head;        //第一个奇数为链表的第一个结点
        ListNode *head1 = even;      //创建个存放奇数的链表

        while (even != NULL && even->next != NULL) //条件写完整
        {
            odd->next = even->next; //下一个奇数位此时偶数的下一个
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
            //用过下边的方法，结果是还要多一层odd的判断，而且时间超限
            /** p = even;
           even = even->next->next;
            p->next = even;
           odd->next =odd->next->next;
        */
        }
        odd->next = head1; //存放偶数的链表与存放奇数的链表链接

        return head;
    }
};
// @lc code=end
