/*
 * @lc app=leetcode.cn id=2085 lang=rust
 *
 * [2085] 统计出现过一次的公共字符串
 *
 * https://leetcode.cn/problems/count-common-words-with-one-occurrence/description/
 *
 * algorithms
 * Easy (71.71%)
 * Likes:    30
 * Dislikes: 0
 * Total Accepted:    28.2K
 * Total Submissions: 36.4K
 * Testcase Example:  '["leetcode","is","amazing","as","is"]\n["amazing","leetcode","is"]'
 *
 * 给你两个字符串数组 words1 和 words2 ，请你返回在两个字符串数组中 都恰好出现一次 的字符串的数目。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：words1 = ["leetcode","is","amazing","as","is"], words2 =
 * ["amazing","leetcode","is"]
 * 输出：2
 * 解释：
 * - "leetcode" 在两个数组中都恰好出现一次，计入答案。
 * - "amazing" 在两个数组中都恰好出现一次，计入答案。
 * - "is" 在两个数组中都出现过，但在 words1 中出现了 2 次，不计入答案。
 * - "as" 在 words1 中出现了一次，但是在 words2 中没有出现过，不计入答案。
 * 所以，有 2 个字符串在两个数组中都恰好出现了一次。
 *
 *
 * 示例 2：
 *
 *
 * 输入：words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
 * 输出：0
 * 解释：没有字符串在两个数组中都恰好出现一次。
 *
 *
 * 示例 3：
 *
 *
 * 输入：words1 = ["a","ab"], words2 = ["a","a","a","ab"]
 * 输出：1
 * 解释：唯一在两个数组中都出现一次的字符串是 "ab" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words1.length, words2.length <= 1000
 * 1 <= words1[i].length, words2[j].length <= 30
 * words1 [i] 和 words2 [j] 都只包含小写英文字母。
 *
 *
 */

// @lc code=start
impl Solution {
    pub fn count_words(words1: Vec<String>, words2: Vec<String>) -> i32 {
        let mut map1 = std::collections::HashMap::new();
        let mut map2 = std::collections::HashMap::new();
        for word in words1 {
            *map1.entry(word).or_insert(0) += 1;
        }
        for word in words2 {
            *map2.entry(word).or_insert(0) += 1;
            let mut res = 0;
            for (word, cnt) in map1 {
                if cnt == 1 && map2.get(&word) == Some(&1) {
                    res += 1;
                }
            }
            return res;
        }
    }
}
// @lc code=end
