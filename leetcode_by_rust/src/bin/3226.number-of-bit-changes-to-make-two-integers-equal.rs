/*
 * @lc app=leetcode.cn id=3226 lang=rust
 * @lcpr version=30204
 *
 * [3226] 使两个整数相等的位更改次数
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_changes(n: i32, k: i32) -> i32 {
        // let mut res = 0;
        // let mut n = n;
        // let mut k = k;

        // while n > 0 || k > 0 {
        //     if (n & 1) == 0 && (k & 1) == 1 {
        //         return -1;
        //     }
        //     if (n & 1) == 1 && (k & 1) == 0 {
        //         res += 1;
        //     }
        //     n >>= 1;
        //     k >>= 1;
        // }

        // res
        if n & k == k {
            (n ^ k).count_ones() as i32
        } else {
            -1
        }
    }
}
// @lc code=end



/*
// @lcpr case=start
// 13\n4\n
// @lcpr case=end

// @lcpr case=start
// 21\n21\n
// @lcpr case=end

// @lcpr case=start
// 14\n13\n
// @lcpr case=end

 */

