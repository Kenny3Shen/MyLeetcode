/*
 * @lc app=leetcode.cn id= 面试题 01.03 lang=rust
 * @lcpr version=30204
 *
 * [ 面试题 01.03] URL 化
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn replace_spaces(s: String, length: i32) -> String {
        // let mut s = s.chars().collect::<Vec<char>>();
        // let mut i = length as usize - 1;
        // let mut j = s.len() - 1;
        // while i < j {
        //     if s[i] == ' ' {
        //         s[j] = '0';
        //         s[j - 1] = '2';
        //         s[j - 2] = '%';
        //         j -= 2;
        //     } else {
        //         s[j] = s[i];
        //     }
        //     i -= 1;
        //     j -= 1;
        // }
        // s.iter().collect()
        
        let mut res = String::new();
        for (i, c) in s.chars().enumerate() {
            if i as i32 >= length {
                break;
            }
            match c {
                ' ' => res.push_str("%20"),
                _ => res.push(c),
            }
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// "Mr John Smith    ", 13\n
// @lcpr case=end

// @lcpr case=start
// "               ", 5\n
// @lcpr case=end

 */

