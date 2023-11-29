/*
 * @lc app=leetcode.cn id=1657 lang=rust
 *
 * [1657] 确定两个字符串是否接近
 *
 * https://leetcode.cn/problems/determine-if-two-strings-are-close/description/
 *
 * algorithms
 * Medium (48.07%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    19.9K
 * Total Submissions: 41K
 * Testcase Example:  '"abc"\n"bca"'
 *
 * 如果可以使用以下操作从一个字符串得到另一个字符串，则认为两个字符串 接近 ：
 * 
 * 
 * 操作 1：交换任意两个 现有 字符。
 * 
 * 
 * 例如，abcde -> aecdb
 * 
 * 
 * 操作 2：将一个 现有 字符的每次出现转换为另一个 现有 字符，并对另一个字符执行相同的操作。
 * 
 * 例如，aacabb -> bbcbaa（所有 a 转化为 b ，而所有的 b 转换为 a ）
 * 
 * 
 * 
 * 
 * 你可以根据需要对任意一个字符串多次使用这两种操作。
 * 
 * 给你两个字符串，word1 和 word2 。如果 word1 和 word2 接近 ，就返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：word1 = "abc", word2 = "bca"
 * 输出：true
 * 解释：2 次操作从 word1 获得 word2 。
 * 执行操作 1："abc" -> "acb"
 * 执行操作 1："acb" -> "bca"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：word1 = "a", word2 = "aa"
 * 输出：false
 * 解释：不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。
 * 
 * 示例 3：
 * 
 * 
 * 输入：word1 = "cabbba", word2 = "abbccc"
 * 输出：true
 * 解释：3 次操作从 word1 获得 word2 。
 * 执行操作 1："cabbba" -> "caabbb"
 * 执行操作 2："caabbb" -> "baaccc"
 * 执行操作 2："baaccc" -> "abbccc"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：word1 = "cabbba", word2 = "aabbss"
 * 输出：false
 * 解释：不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * word1 和 word2 仅包含小写英文字母
 * 
 * 
 */

// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn close_strings(word1: String, word2: String) -> bool {
        let (m,n) = (word1.len(), word2.len());
        if m != n {
            return false;
        }
        let mut map1 = HashMap::new();
        let mut map2 = HashMap::new();
        for c in word1.chars() {
            *map1.entry(c).or_insert(0) += 1;
        }
        for c in word2.chars() {
            *map2.entry(c).or_insert(0) += 1;
            if word1.chars().all(|x| x != c) {
                return false;
            }
        }
        let mut v1: Vec<_> = map1.values().collect();
        let mut v2: Vec<_> = map2.values().collect();
        v1.sort();
        v2.sort();
        v1 == v2
    }
}
// @lc code=end

