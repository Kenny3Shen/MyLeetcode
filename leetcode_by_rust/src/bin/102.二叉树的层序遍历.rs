/*
 * @lc app=leetcode.cn id=102 lang=rust
 *
 * [102] 二叉树的层序遍历
 */

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
use std::io::Read;
use std::rc::Rc;
impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut res = Vec::new();
        let mut queue = VecDeque::new();
        if let Some(node) = root {
            queue.push_back(node);
        } else {
            return res;
        }
        while queue.is_empty() != true {
            let n = queue.len();
            let mut level = Vec::new();
            for _ in 0..n {
                if let Some(node) = queue.pop_front() {
                    // 需要访问左右子树，所以需要 borrow，使用 clone 会导致所有权转移，无法再次使用
                    let node = node.borrow(); 
                    level.push (node.val); //i32 类型，不用显式 clone
                    if let Some(left) = &node.left {
                        queue.push_back (left.clone ()); // Rc<RefCell<TreeNode>> 类型，需要显式 clone
                    }
                    if let Some(right) = &node.right {
                        queue.push_back(right.clone());
                    }
                }
            }
            res.push(level)
        }
        res
    }
}
// @lc code=end
