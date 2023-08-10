/*
 * @lc app=leetcode.cn id=820 lang=rust
 *
 * [820] 单词的压缩编码
 *
 * https://leetcode.cn/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (52.10%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    70.3K
 * Total Submissions: 135K
 * Testcase Example:  '["time","me","bell"]'
 *
 * 单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices 组成，且满足：
 *
 *
 * words.length == indices.length
 * 助记字符串 s 以 '#' 字符结尾
 * 对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#' 字符结束（但不包括 '#'）的 子字符串 恰好与
 * words[i] 相等
 *
 *
 * 给你一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：words = ["time", "me", "bell"]
 * 输出：10
 * 解释：一组有效编码为 s = "time#bell#" 和 indices = [0, 2, 5] 。
 * words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#' 结束的子字符串，如加粗部分所示
 * "time#bell#"
 * words[1] = "me" ，s 开始于 indices[1] = 2 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
 * words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#' 结束的子字符串，如加粗部分所示
 * "time#bell#"
 *
 *
 * 示例 2：
 *
 *
 * 输入：words = ["t"]
 * 输出：2
 * 解释：一组有效编码为 s = "t#" 和 indices = [0] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * words[i] 仅由小写字母组成
 *
 *
 */

// @lc code=start
#[derive(Clone)]
struct TrieNode {
    is_end: bool,
    children: Vec<Option<Box<TrieNode>>>,
}
impl TrieNode {
    fn new() -> Self {
        Self {
            is_end: false,
            children: vec![None; 26],
        }
    }
    fn insert(&mut self, w: &str) -> i32 {
        let mut node = self;
        let mut is_new_word = false;
        for c in w.chars() {
            let idx = c as usize - 'a' as usize;
            if node.children[idx].is_none() {
                is_new_word = true;
                node.children[idx] = Some(Box::new(TrieNode::new()));
            }
            node = node.children[idx].as_mut().unwrap();
        }
        node.is_end = true;

        if is_new_word {
            w.len() as i32 + 1
        } else {
            0
        }
    }
}

impl Solution {
    pub fn minimum_length_encoding(words: Vec<String>) -> i32 {
        let mut words: Vec<String> = words.iter().map(|w| w.chars().rev().collect()).collect();
        words.sort_unstable_by(|a, b| b.len().cmp(&a.len()));
        let mut trie = TrieNode::new();
        let mut res: i32 = 0;
        for word in words {
            res += trie.insert(&word);
        }
        res
    }
}
// @lc code=end
