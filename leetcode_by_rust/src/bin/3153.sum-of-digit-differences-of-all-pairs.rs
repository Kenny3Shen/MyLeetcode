/*
 * @lc app=leetcode.cn id=3153 lang=rust
 * @lcpr version=30204
 *
 * [3153] 所有数对中数位不同之和
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn sum_digit_differences(nums: Vec<i32>) -> i64 {
        let mut ans = 0;
        let mut cnt = vec![vec![0; 10]; nums[0].to_string().len()];
        
        for (k, mut x) in nums.iter().enumerate() {
            let mut x = *x;
            let mut i = 0;
            while x > 0 {
                let d = x % 10;
                x /= 10;
                ans += k - cnt[i][d as usize];
                cnt[i][d as usize] += 1;
                i += 1;
            }
        }
        ans as i64c
    }
}
// @lc code=end

/*
// @lcpr case=start
// [13,23,12]\n
// @lcpr case=end

// @lcpr case=start
// [10,10,10,10]\n
// @lcpr case=end

 */
