/*
 * @lc app=leetcode.cn id=965 lang=rust
 *
 * [965] 单值二叉树
 *
 * https://leetcode.cn/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (70.57%)
 * Likes:    192
 * Dislikes: 0
 * Total Accepted:    82.6K
 * Total Submissions: 117.1K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
 *
 * 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[1,1,1,1,1,null,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：[2,2,2,5,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给定树的节点数范围是 [1, 100]。
 * 每个节点的值都是整数，范围为 [0, 99] 。
 *
 *
 */
// @lc code=start
// Definition for a binary tree node.
//#[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//     pub val: i32,
//     pub left: Option<Rc<RefCell<TreeNode>>>,
//     pub right: Option<Rc<RefCell<TreeNode>>>,
// }

// impl TreeNode {
//     #[inline]
//     pub fn new(val: i32) -> Self {
//         TreeNode {
//             val,
//             left: None,
//             right: None,
//         }
//     }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn is_unival_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            Some(node) => {
                let node = node.borrow();

                Self::step(&node.left, node.val) && Self::step(&node.right, node.val)
            }
            None => true,
        }
    }

    fn step(node: &Option<Rc<RefCell<TreeNode>>>, val: i32) -> bool {
        match node {
            Some(node) => {
                let node = node.borrow();

                node.val == val && Self::step(&node.left, val) && Self::step(&node.right, val)
            }
            None => true,
        }
    }
}
// @lc code=end
