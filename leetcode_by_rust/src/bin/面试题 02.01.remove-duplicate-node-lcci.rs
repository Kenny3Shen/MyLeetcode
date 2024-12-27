/*
 * @lc app=leetcode.cn id= 面试题 02.01 lang=rust
 * @lcpr version=30204
 *
 * [ 面试题 02.01] 移除重复节点
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
    pub fn remove_duplicate_nodes(mut head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if let Some(mut head) = head {
            let mut set = std::collections::HashSet::with_capacity(20001);
            let mut cur = &mut head;
            set.insert(cur.val);
            while let Some(cur_next) = &cur.next {
                if set.contains(&cur_next.val) {
                    cur.next = cur.next.take().unwrap().next;
                } else {
                    set.insert(cur_next.val);
                    cur = cur.next.as_mut().unwrap();
                }
            }
            Some(head)
        } else {
            None
        } 
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1, 2, 3, 3, 2, 1]\n
// @lcpr case=end

// @lcpr case=start
// [1, 1, 1, 1, 2]\n
// @lcpr case=end

 */
