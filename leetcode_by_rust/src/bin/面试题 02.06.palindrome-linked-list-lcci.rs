/*
 * @lc app=leetcode.cn id= 面试题 02.06 lang=rust
 * @lcpr version=30204
 *
 * [ 面试题 02.06] 回文链表
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }

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
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
          if head.is_none() {
            return true;
    }
    let mut vec = vec![];
    let mut cur = head;
    while let Some(node) = cur {
        vec.push(node.val);
        cur = node.next;
    }
    let mut left = 0;
    let mut right = vec.len() - 1;
    while left < right {
        if vec[left] != vec[right] {
            return false;
        }
        left += 1;
        right -= 1;
    }
    true
    }
}
// @lc code=end



/*
// @lcpr case=start
// 1->2\n
// @lcpr case=end

// @lcpr case=start
// 1->2->2->1\n
// @lcpr case=end

 */

