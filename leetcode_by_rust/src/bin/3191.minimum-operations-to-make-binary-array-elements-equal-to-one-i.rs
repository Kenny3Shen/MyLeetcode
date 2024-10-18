/*
 * @lc app=leetcode.cn id=3191 lang=rust
 * @lcpr version=30204
 *
 * [3191] 使二进制数组全部等于 1 的最少操作次数 I
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn min_operations(mut nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut cnt = 0;
        for i in 0..n {
            if nums[i] == 0 {
                if i >= n - 2 {
                    return -1;
                }
                cnt += 1;
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
            }
        }
        cnt
    }
}
// @lc code=end

/*
// @lcpr case=start
// [0,1,1,1,0,0]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1,1]\n
// @lcpr case=end

 */
