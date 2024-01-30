/*
 * @lc app=leetcode.cn id=2808 lang=rust
 *
 * [2808] 使循环数组所有元素相等的最少秒数
 */

// @lc code=start
impl Solution {
    pub fn minimum_seconds(nums: Vec<i32>) -> i32 {
        use std::collections::HashMap;

        let nlen = nums.len();
        let mut positions = HashMap::new();
        for (i, n) in nums.into_iter().enumerate() {
            positions.entry(n).or_insert(vec![]).push(i);
        }

        positions
            .into_values()
            .map(|pos| {
                let len = pos.len();
                let mut pre = pos[0];
                pos.into_iter()
                    .cycle()
                    .take(len + 1)
                    .skip(1)
                    .map(|p| {
                        let pp = pre;
                        pre = p;
                        (p + nlen - pp) % nlen
                    })
                    .map(|p| if p == 0 { nlen } else { p })
                    .max()
                    .unwrap()
            })
            .min()
            .map(|dis| dis / 2)
            .unwrap() as i32
    }
}
// @lc code=end
