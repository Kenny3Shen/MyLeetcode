/*
 * @lc app=leetcode.cn id=2815 lang=rust
 * @lcpr version=30204
 *
 * [2815] 数组中的最大数对和
 */


// @lcpr-template-start

use std::i32;

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn max_sum(nums: Vec<i32>) -> i32 {
        fn get_max_digit(mut num: i32) -> usize {
            let mut max_digit = 0;
            while num > 0 {
                max_digit = max_digit.max(num % 10);
                num /= 10;
            }
            max_digit as usize
        }

        let mut max_num_per_digital = vec![i32::MIN; 10];
        let mut res = -1;
        for num in nums {
            let max_digit = get_max_digit(num);
            res = res.max(num + max_num_per_digital[max_digit]);
            max_num_per_digital[max_digit] = max_num_per_digital[max_digit].max(num);
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [51,71,17,24,42]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

 */

