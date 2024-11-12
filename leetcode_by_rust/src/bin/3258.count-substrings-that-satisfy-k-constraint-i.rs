/*
 * @lc app=leetcode.cn id=3258 lang=rust
 * @lcpr version=30204
 *
 * [3258] 统计满足 K 约束的子字符串数量 I
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn count_k_constraint_substrings(s: String, k: i32) -> i32 {
        let n = s.len();
        let s: Vec<u8> = s.bytes().collect();
        let mut res = 0;
        for i in 0..n {
            let mut count = [0, 0];
            for j in i..n {
                count[s[j] as usize - b'0' as usize] += 1;
                if count[0] > k && count[1] > k {
                    break;
                }
                res += 1;
            }
        }
        res
    }
}

// @lc code=end



/*
// @lcpr case=start
// "10101"\n1\n
// @lcpr case=end

// @lcpr case=start
// "1010101"\n2\n
// @lcpr case=end

// @lcpr case=start
// "11111"\n1\n
// @lcpr case=end

 */

