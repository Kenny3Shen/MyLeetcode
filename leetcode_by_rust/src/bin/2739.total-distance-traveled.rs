/*
 * @lc app=leetcode.cn id=2739 lang=rust
 * @lcpr version=30204
 *
 * [2739] 总行驶距离
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn distance_traveled(mut main_tank: i32, mut additional_tank: i32) -> i32 {
        let mut used_gas = 0;
        while true {
            let cur = main_tank - 5;
            if cur < 0 {
                used_gas += main_tank;
                break;
            } else if cur == 0 {
                used_gas += 5;
                if additional_tank > 0 {
                    used_gas += 1;
                }
                break;
            } else {
                used_gas += 5;
                main_tank -= 5;
                if additional_tank > 0 {
                    main_tank += 1;
                    additional_tank -= 1;
                }
            }
        }
        used_gas * 10
    }
}
// @lc code=end



/*
// @lcpr case=start
// 5\n10\n
// @lcpr case=end

// @lcpr case=start
// 1\n2\n
// @lcpr case=end

 */

