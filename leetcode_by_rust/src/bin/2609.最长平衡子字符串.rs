/*
 * @lc app=leetcode.cn id=2609 lang=rust
 *
 * [2609] 最长平衡子字符串
 *
 * https://leetcode.cn/problems/find-the-longest-balanced-substring-of-a-binary-string/description/
 *
 * algorithms
 * Easy (49.27%)
 * Likes:    21
 * Dislikes: 0
 * Total Accepted:    9.8K
 * Total Submissions: 19.2K
 * Testcase Example:  '"01000111"'
 *
 * 给你一个仅由 0 和 1 组成的二进制字符串 s 。  
 * 
 * 如果子字符串中 所有的 0 都在 1 之前 且其中 0 的数量等于 1 的数量，则认为 s
 * 的这个子字符串是平衡子字符串。请注意，空子字符串也视作平衡子字符串。 
 * 
 * 返回  s 中最长的平衡子字符串长度。
 * 
 * 子字符串是字符串中的一个连续字符序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "01000111"
 * 输出：6
 * 解释：最长的平衡子字符串是 "000111" ，长度为 6 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "00111"
 * 输出：4
 * 解释：最长的平衡子字符串是 "0011" ，长度为  4 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "111"
 * 输出：0
 * 解释：除了空子字符串之外不存在其他平衡子字符串，所以答案为 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 50
 * '0' <= s[i] <= '1'
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn find_the_longest_balanced_substring(s: String) -> i32 {
        let mut res = 0;
        let mut vec = vec![0,0];
        for i in 0..s.len() {
            if s.chars().nth(i).unwrap() == '1' {
                vec[1] += 1;
                res = res.max(vec[0].min(vec[1]) * 2);
            }else if (i == 0) || (s.chars().nth(i - 1).unwrap() == '1') {
                vec[0] = 1;
                vec[1] = 0;
            }else {
                vec[0] += 1;
            }
        }
        res
    }
}
// @lc code=end

