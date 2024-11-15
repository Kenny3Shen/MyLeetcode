/*
 * @lc app=leetcode.cn id=2785 lang=rust
 * @lcpr version=30204
 *
 * [2785] 将字符串中的元音字母排序
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn sort_vowels(s: String) -> String {
        let vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
        let mut s = s.chars().collect::<Vec<char>>();
        let mut s_vowels = s.iter().filter(|&c| vowels.contains(c)).copied().collect::<Vec<char>>();
        s_vowels.sort_unstable();
        let mut s_vowels_iter = s_vowels.iter();
        let mut res = String::new();
        for c in s {
            if vowels.contains(&c) {
                res.push(*s_vowels_iter.next().unwrap());
            } else {
                res.push(c);
            }
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// "lEetcOde"\n
// @lcpr case=end

// @lcpr case=start
// "lYmpH"\n
// @lcpr case=end

 */

