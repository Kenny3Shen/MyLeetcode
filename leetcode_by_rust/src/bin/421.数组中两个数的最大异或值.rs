/*
 * @lc app=leetcode.cn id=421 lang=rust
 *
 * [421] 数组中两个数的最大异或值
 *
 * https://leetcode.cn/problems/maximum-xor-of-two-numbers-in-an-array/description/
 *
 * algorithms
 * Medium (61.28%)
 * Likes:    535
 * Dislikes: 0
 * Total Accepted:    44.6K
 * Total Submissions: 72.8K
 * Testcase Example:  '[3,10,5,25,2,8]'
 *
 * 给你一个整数数组 nums ，返回 nums[i] XOR nums[j] 的最大运算结果，其中 0 ≤ i ≤ j < n 。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [3,10,5,25,2,8]
 * 输出：28
 * 解释：最大运算结果是 5 XOR 25 = 28.
 *
 * 示例 2：
 *
 *
 * 输入：nums = [14,70,53,83,49,91,36,80,92,51,66,70]
 * 输出：127
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 2 * 10^5
 * 0 <= nums[i] <= 2^31 - 1
 *
 *
 *
 *
 */

// @lc code=start
#[derive(Default)]
struct Trie(Option<Box<Trie>>, Option<Box<Trie>>);

impl Trie {
    fn new() -> Self {
        Default::default()
    }

    fn insert(&mut self, num: i32) {
        (0..31).rev().fold(self, |node, k| match (num >> k) & 1 {
            0 => node.0.get_or_insert_with(Default::default),
            _ => node.1.get_or_insert_with(Default::default),
        });
    }

    fn check(&self, num: i32) -> i32 {
        let mut c = self;
        let mut x = 0;
        for k in (0..31).rev() {
            if ((num >> k) & 1) == 0 {
                if let Some(r) = &c.1 {
                    c = r;
                    x = (x << 1) + 1;
                } else if let Some(l) = &c.0 {
                    c = l;
                    x <<= 1;
                }
            } else {
                if let Some(l) = &c.0 {
                    c = l;
                    x = (x << 1) + 1;
                } else if let Some(r) = &c.1 {
                    c = r;
                    x <<= 1;
                }
            }
        }
        x
    }
}

impl Solution {
    pub fn find_maximum_xor(nums: Vec<i32>) -> i32 {
        let mut x = 0;
        let mut trie = Trie::new();
        for i in 1..nums.len() {
            trie.insert(nums[i - 1]);
            x = x.max(trie.check(nums[i]));
        }
        x
    }
}

// @lc code=end
