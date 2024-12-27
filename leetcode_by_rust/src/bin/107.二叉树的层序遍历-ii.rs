/*
 * @lc app=leetcode.cn id=107 lang=rust
 *
 * [107] 二叉树的层序遍历 II
 */
mod leetcode;
use leetcode::TreeNode;
// @lc code=start
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

impl Solution {
    pub fn level_order_bottom(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut ans = Vec::new();
        let mut q = VecDeque::new();
        if let Some(x) = root {
            q.push_back(x);
        } else {
            return ans;
        }
        while !q.is_empty() {
            let n = q.len();
            let mut vals = Vec::with_capacity (n); // 预分配空间
            for _ in 0..n {
                if let Some(node) = q.pop_front() {
                    let mut x = node.borrow_mut();
                    vals.push(x.val);
                    if let Some(left) = x.left.take() {
                        q.push_back(left);
                    }
                    if let Some(right) = x.right.take() {
                        q.push_back(right);
                    }
                }
            }
            ans.push(vals);
        }
        ans.reverse();
        ans
    }
}
// @lc code=end
