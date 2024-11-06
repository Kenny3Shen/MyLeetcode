/*
 * @lc app=leetcode.cn id=3255 lang=rust
 * @lcpr version=30204
 *
 * [3255] 长度为 K 的子数组的能量值 II
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn results_array(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let n = nums.len();
        let mut cnt = 0;
        let mut ans = vec![-1; n - k as usize + 1];

        for i in 0..n {
            cnt = if i == 0 || nums[i] - nums[i - 1] != 1 { 1 } else { cnt + 1 };
            if cnt >= k {
                ans[i - k as usize + 1] = nums[i];
            }
        }
        ans
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,3,2,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,2,3,2]\n2\n
// @lcpr case=end

 */

