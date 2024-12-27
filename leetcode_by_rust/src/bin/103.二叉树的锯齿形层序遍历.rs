/*
 * @lc app=leetcode.cn id=103 lang=rust
 *
 * [103] 二叉树的锯齿形层序遍历
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
    pub fn zigzag_level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        let mut q = VecDeque::new();
        let mut rev = true;
        if let Some(node) = root {
            q.push_back(node);
        }
        while !q.is_empty() {
            rev = !rev;
            let mut level = Vec::new();
            let n = q.len();
            for _ in 0..n {
                if let Some(node) = q.pop_front() {
                    let node = node.borrow_mut();
                    level.push(node.val);
                    if let Some(left) = &node.left {
                        q.push_back(left.clone());
                    }
                    if let Some(right) = &node.right {
                        q.push_back(right.clone());
                    }
                }
            }
            if rev {
                level.reverse();
            }
            res.push(level);
        }
        res
    }
}
// @lc code=end
