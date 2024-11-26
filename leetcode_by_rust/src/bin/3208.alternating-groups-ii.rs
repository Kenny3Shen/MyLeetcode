/*
 * @lc app=leetcode.cn id=3208 lang=rust
 * @lcpr version=30204
 *
 * [3208] 交替组 II
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn number_of_alternating_groups(colors: Vec<i32>, k: i32) -> i32 {
        let n = colors.len() as i32;
        let mut res = 0;
        let mut cnt = 1;
        for i in (-k + 2)..n {
            if colors[((i + n) % n) as usize] != colors[((i - 1 + n) % n) as usize] {
                cnt += 1;
            } else {
                cnt = 1;
            }
            if cnt >= k {
                res += 1;
            }
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [0,1,0,1,0]\n3\n
// @lcpr case=end

// @lcpr case=start
// [0,1,0,0,1,0,1]\n6\n
// @lcpr case=end

// @lcpr case=start
// [1,1,0,1]\n4\n
// @lcpr case=end

 */

