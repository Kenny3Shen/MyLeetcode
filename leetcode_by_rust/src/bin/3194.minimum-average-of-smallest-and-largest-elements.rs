/*
 * @lc app=leetcode.cn id=3194 lang=rust
 * @lcpr version=30204
 *
 * [3194] 最小元素和最大元素的最小平均值
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn minimum_average(mut nums: Vec<i32>) -> f64 {
        nums.sort();
        let (mut i, mut j) = (0, nums.len() - 1);
        let mut res = f64::MAX;
        while i < j {
            res = res.min((nums[i] + nums[j]) as f64 / 2.0);
            i += 1;
            j -= 1;
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [7,8,3,4,15,13,4,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,9,8,3,10,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,7,8,9]\n
// @lcpr case=end

 */

