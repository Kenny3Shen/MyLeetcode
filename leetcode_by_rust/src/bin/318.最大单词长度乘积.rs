/*
 * @lc app=leetcode.cn id=318 lang=rust
 *
 * [318] 最大单词长度乘积
 *
 * https://leetcode.cn/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (72.48%)
 * Likes:    432
 * Dislikes: 0
 * Total Accepted:    71K
 * Total Submissions: 97.9K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * 给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j])
 * 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * 输出：16 
 * 解释：这两个单词为 "abcw", "xtfn"。
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
 * 输出：4 
 * 解释：这两个单词为 "ab", "cd"。
 * 
 * 示例 3：
 * 
 * 
 * 输入：words = ["a","aa","aaa","aaaa"]
 * 输出：0 
 * 解释：不存在这样的两个单词。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] 仅包含小写字母
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn max_product(words: Vec<String>) -> i32 {
        let mut res = 0;
        let mut vec = Vec::with_capacity(words.len());
        for word in words {
            let mut mask = 0;
            for c in word.chars() {
                mask |= 1 << (c as u8 - b'a');
            }
            vec.push((word.len(), mask));
        }
        for i in 0..vec.len() {
            for j in i + 1..vec.len() {
                if vec[i].1 & vec[j].1 == 0 {
                    res = res.max(vec[i].0 * vec[j].0);
                }
            }
        }
        res as i32

    }
}
// @lc code=end

