/*
 * @lc app=leetcode.cn id=2 lang=rust
 * @lcpr version=30204
 *
 * [2] 两数相加
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
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy = Some(Box::new(ListNode::new(0)));
        let (mut p, mut q, mut curr) = (l1, l2, dummy.as_mut());
        let mut carry = 0;
        while p.is_some() || q.is_some() {
            let sum = carry + p.as_ref().map_or(0, |node| node.val) + q.as_ref().map_or(0, |node| node.val);
            carry = sum / 10;
            if let Some(node) = curr {
                node.next = Some(Box::new(ListNode::new(sum % 10)));
                curr = node.next.as_mut();
            }
            if let Some(node) = p {
                p = node.next;
            }
            if let Some(node) = q {
                q = node.next;
            }
        }
        if carry > 0 {
            if let Some(node) = curr {
                node.next = Some(Box::new(ListNode::new(carry)));
            }
        }
        dummy.unwrap().next
    }
}
// @lc code=end



/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */

