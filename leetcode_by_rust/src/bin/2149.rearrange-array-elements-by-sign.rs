/*
 * @lc app=leetcode.cn id=2149 lang=rust
 * @lcpr version=30204
 *
 * [2149] 按符号重排数组
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn rearrange_array(nums: Vec<i32>) -> Vec<i32> {
        let pos = nums.iter().filter(|&x| *x > 0).cloned().collect::<Vec<i32>>();
        let neg = nums.iter().filter(|&x| *x < 0).cloned().collect::<Vec<i32>>();
        let mut res = vec![];
        for i in 0..nums.len() / 2 {
            res.push(pos[i]);
            res.push(neg[i]);
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [3,1,-2,-5,2,-4]\n
// @lcpr case=end

// @lcpr case=start
// [-1,1]\n
// @lcpr case=end

 */

