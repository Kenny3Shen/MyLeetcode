/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (43.00%)
 * Likes:    605
 * Dislikes: 0
 * Total Accepted:    117K
 * Total Submissions: 271.8K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
 */
#include <vector>
#include <stack>
using namespace std;

// @lc code=start

//* Definition for singly-linked list.
/* struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}; */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        /* if (!head)
            return true;
        vector<int> v;
        while (head)
        {
            v.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = v.size() - 1;
        while(left < right)
        {
            if(v[left++] != v[right--])
                return false;
        }
        return true; */
        stack<int> st;
        ListNode *cur = head;
        while (cur)
        {
            st.push(cur->val);
            cur = cur->next;
        }
        int size = st.size() / 2; //比较一半即可
        cur = head;
        for (int i = 0; i < size; i++, cur = cur->next)
        {
            if (cur->val != st.top())
                return false;
            st.pop();
        }
        return true;
    }
};
// @lc code=end
