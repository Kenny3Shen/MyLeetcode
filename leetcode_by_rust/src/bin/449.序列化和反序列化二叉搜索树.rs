/*
 * @lc app=leetcode.cn id=449 lang=rust
 *
 * [449] 序列化和反序列化二叉搜索树
 *
 * https://leetcode.cn/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (60.51%)
 * Likes:    495
 * Dislikes: 0
 * Total Accepted:    59K
 * Total Submissions: 95.5K
 * Testcase Example:  '[2,1,3]'
 *
 * 序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。
 * 
 * 设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。
 * 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。
 * 
 * 编码的字符串应尽可能紧凑。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [2,1,3]
 * 输出：[2,1,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数范围是 [0, 10^4]
 * 0 <= Node.val <= 10^4
 * 题目数据 保证 输入的树是一棵二叉搜索树。
 * 
 * 
 */

// @lc code=start
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }

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
use core::borrow;
use std::rc::Rc;
use std::cell::RefCell;
use std::str::SplitWhitespace;
#[derive(Default)]
struct Codec {

}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Codec {
    fn new() -> Self {
        Codec {  }
    }

    fn serialize(&self, root: Option<Rc<RefCell<TreeNode>>>) -> String {
        if let Some(node) = root {
            format!(
                "{} {} {}",
                node.borrow().val,
                self.serialize(node.borrow().left.clone()),
                self.serialize(node.borrow().right.clone())
            )
        } else {
            "#".to_string()
        }
    }

    fn deserialize(&self, data: String) -> Option<Rc<RefCell<TreeNode>>> {
        let mut iter = data.split_whitespace();
        self.deserialize_helper(&mut iter)
    }

    fn deserialize_helper(&self, iter: &mut SplitWhitespace) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(val) = iter.next() {
            if val != "#" {
                let node = Rc::new(RefCell::new(TreeNode::new(val.parse::<i32>().unwrap())));
                node.borrow_mut().left = self.deserialize_helper(iter);
                node.borrow_mut().right = self.deserialize_helper(iter);
                Some(node)
            } else {
                None
            }
        } else {
            None
        }
    }
}

/*
 * Your Codec object will be instantiated and called as such:
 * let obj = Codec::new();
 * let data: String = obj.serialize(strs);
 * let ans: Option<Rc<RefCell<TreeNode>>> = obj.deserialize(data);
 */
// @lc code=end

