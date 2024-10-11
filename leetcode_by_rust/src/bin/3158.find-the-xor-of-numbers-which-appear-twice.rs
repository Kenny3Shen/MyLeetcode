/*
 * @lc app=leetcode.cn id=3158 lang=rust
 * @lcpr version=30204
 *
 * [3158] 求出出现两次数字的 XOR 值
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn duplicate_numbers_xor(nums: Vec<i32>) -> i32 {
        // let mut map = std::collections::HashMap::new();
        // for n in nums {
        //     *map.entry(n).or_insert(0) += 1;
        // }
        // let mut res = 0;
        // for (k, v) in map {
        //     if v == 2 {
        //         res = res ^ k;
        //     }
        // }
        // res

        // notice that nums[i] <= 50
        // so that can be stored in a 64-bit integer
        let mut ans = 0;
        let mut vis = 0i64;
        for x in nums {
            if (vis >> x & 1) > 0 {
                ans = ans ^ x;
            } else {
                vis |= 1 << x;
            }
        }
        ans
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,1]\n
// @lcpr case=end

 */

