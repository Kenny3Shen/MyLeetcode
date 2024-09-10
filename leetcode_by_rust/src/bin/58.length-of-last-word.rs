/*
 * @lc app=leetcode.cn id=58 lang=rust
 * @lcpr version=30204
 *
 * [58] 最后一个单词的长度
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut s = s.trim_end();
        let mut last_word_len = 0;
        for c in s.chars().rev() {
            if c == ' ' {
                break;
            }
            last_word_len += 1;
        }
        last_word_len
    }
}
// @lc code=end



/*
// @lcpr case=start
// "Hello World"\n
// @lcpr case=end

// @lcpr case=start
// "   fly me   to   the moon  "\n
// @lcpr case=end

// @lcpr case=start
// "luffy is still joyboy"\n
// @lcpr case=end

 */

