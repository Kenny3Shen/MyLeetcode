/*
 * @lc app=leetcode.cn id= 面试题 01.02 lang=rust
 * @lcpr version=30204
 *
 * [ 面试题 01.02] 判定是否互为字符重排
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn check_permutation(s1: String, s2: String) -> bool {
        // if s1.len() != s2.len() {
        //     return false;
        // }
        // let mut s1 = s1.chars().collect::<Vec<char>>();
        // let mut s2 = s2.chars().collect::<Vec<char>>();
        // s1.sort();
        // s2.sort();
        // s1 == s2

        // if s1.len() != s2.len() {
        //     return false;
        // }
        // let mut map = std::collections::HashMap::new();
        // for c in s1.chars() {
        //     *map.entry(c).or_insert(0) += 1;
        // }
        // for c in s2.chars() {
        //     match map.get_mut(&c) {
        //         Some(v) => {
        //             *v -= 1;
        //             if *v < 0 {
        //                 return false;
        //             }
        //         }
        //         None => {
        //             return false;
        //         }
        //     }
        // }
        // true

        if s1.len() != s2.len() {
            return false;
        }
        s1.chars().all(|c| s1.matches(c).count() == s2.matches(c).count())
    }
}
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"bca"\n
// @lcpr case=end

// @lcpr case=start
// "abc"\n"bad"\n
// @lcpr case=end

 */
