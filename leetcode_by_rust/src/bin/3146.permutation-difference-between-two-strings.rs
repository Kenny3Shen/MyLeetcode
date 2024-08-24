/*
 * @lc app=leetcode.cn id=3146 lang=rust
 * @lcpr version=30204
 *
 * [3146] 两个字符串的排列差
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn find_permutation_difference(s: String, t: String) -> i32 {
        let mut map = std::collections::HashMap::new();
        s.chars().enumerate().for_each(|(i, c)| {
            //map.insert(c, i as i32);
            map.entry(c).or_insert(i as i32);
        });

        t.chars()
            .enumerate()
            .fold(0, |acc, (i, c)| acc + (i as i32 - map[&c]).abs())
    }
}
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"bac"\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n"edbac"\n
// @lcpr case=end

 */
