/*
 * @lc app=leetcode.cn id=2980 lang=rust
 * @lcpr version=30204
 *
 * [2980] 检查按位或是否存在尾随零
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn has_trailing_zeros(nums: Vec<i32>) -> bool {
        // 找到任意两个不同的偶数
        nums.iter().filter(|&&x| x % 2 == 0).count() >= 2
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,8,16]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,5,7,9]\n
// @lcpr case=end

 */

