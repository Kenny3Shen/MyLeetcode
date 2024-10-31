/*
 * @lc app=leetcode.cn id=3162 lang=rust
 * @lcpr version=30204
 *
 * [3162] 优质数对的总数 I
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn number_of_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> i32 {
        let mut res = 0;
        for n1 in &nums1 {
            for n2 in &nums2 {
                if n1 % (n2  * k) == 0 {
                    res += 1;
                }
            }
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,3,4]\n[1,3,4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,12]\n[2,4]\n3\n
// @lcpr case=end

 */

