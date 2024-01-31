/*
 * @lc app=leetcode.cn id=2670 lang=rust
 *
 * [2670] 找出不同元素数目差数组
 */

// @lc code=start
impl Solution {
    pub fn distinct_difference_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut res = vec![0; n + 1];
        let mut s = std::collections::HashSet::new();

        for i in (0..n).rev() {
            s.insert(nums[i]);
            res[i] = s.len() as i32;
        }

        let mut ans = Vec::new();
        s.clear();
        for i in 0..n {
            s.insert(nums[i]);
            ans.push(s.len() as i32 - res[i + 1]);
        }
        ans
    }
}
// @lc code=endF
