/*
 * @lc app=leetcode.cn id=344 lang=rust
 *
 * [344] 反转字符串
 *
 * https://leetcode.cn/problems/reverse-string/description/
 *
 * algorithms
 * Easy (79.92%)
 * Likes:    840
 * Dislikes: 0
 * Total Accepted:    815K
 * Total Submissions: 1M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
 * 
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = ["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = ["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] 都是 ASCII 码表中的可打印字符
 * 
 * 
 */

// @lc code=start
impl Solution {
    pub fn reverse_string(mut s: &mut Vec<char>) {
        let n = s.len();
        let (mut i , mut j) = (0, n - 1);
        while i < j {
            s.swap(i, j);
            i += 1;
            j -= 1;
        }
    }
    
}
// @lc code=end

