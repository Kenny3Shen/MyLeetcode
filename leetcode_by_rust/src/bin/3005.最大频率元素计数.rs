/*
 * @lc app=leetcode.cn id=3005 lang=rust
 *
 * [3005] 最大频率元素计数
 */

// @lc code=start
impl Solution {
    pub fn max_frequency_elements(nums: Vec<i32>) -> i32 {
        let mut map = std::collections::HashMap::new();
        for num in nums {
            *map.entry(num).or_insert(0) += 1;
        }
        let mut mx = 0;
        for &v in map.values() {
            mx = mx.max(v);
        }
        let mut res = 0;
        for &v in map.values() {
            if v == mx {
                res += v;
            }
        }
        res
    }
}
// @lc code=end

