/*
 * @lc app=leetcode.cn id=82 lang=rust
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (53.63%)
 * Likes:    1259
 * Dislikes: 0
 * Total Accepted:    400.9K
 * Total Submissions: 742K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,3,4,4,5]
 * 输出：[1,2,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,1,1,2,3]
 * 输出：[2,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围 [0, 300] 内
 * -100 <= Node.val <= 100
 * 题目数据保证链表已经按升序 排列
 *
 *
 */

// @lc code=start
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn delete_duplicates(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Box::new (ListNode::new (0)); // 创建一个哑节点作为新链表的头部
        let mut tail = &mut dummy; // `tail` 用于跟踪新链表的最后一个节点
        let mut prev_val = None; // `prev_val` 用于记录前一个节点的值
        while let Some(mut node) = head {
            head = node.next.take (); // 取出当前节点，并将 `head` 移动到下一个节点
            let node_val = node.val; // 在潜在移动 `node` 之前，存储当前节点的值
            if head.as_ref().map_or(true, |next| next.val != node_val)
                && prev_val.map_or(true, |val| val != node_val)
            {
                tail.next = Some (node); // 如果当前节点是唯一的（值不等于下一个节点或前一个节点的值），则将其添加到新链表中

                tail = tail.next.as_mut ().unwrap (); // 更新 `tail` 为新链表的最后一个节点
            }
            prev_val = Some (node_val); // 更新 `prev_val` 为当前节点的值
        }
        dummy.next
    }
}
// @lc code=end
