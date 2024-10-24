/*
 * @lc app=leetcode.cn id=2951 lang=rust
 * @lcpr version=30204
 *
 * [2951] 找出峰值
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn find_peaks(mountain: Vec<i32>) -> Vec<i32> {
        let mut res = vec![];
        for i in 1..mountain.len()-1 {
            if mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1] {
                res.push(i as i32);
            }
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [2,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,4,3,8,5]\n
// @lcpr case=end

 */

