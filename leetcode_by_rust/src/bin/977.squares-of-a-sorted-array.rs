/*
 * @lc app=leetcode.cn id=977 lang=rust
 * @lcpr version=30204
 *
 * [977] 有序数组的平方
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        // let mut nums = nums.into_iter()
        //     .map(|x| x * x)
        //     .collect::<Vec<i32>>();
        // nums.sort();
        // nums   

        let mut i = 0;
        let mut j = nums.len() - 1;
        let mut k = nums.len() - 1;
        let mut res = vec![0; nums.len()];
        while i <= j {
            if nums[i].abs() > nums[j].abs() {
                res[k] = nums[i] * nums[i];
                i += 1;
            } else {
                res[k] = nums[j] * nums[j];
                j -= 1; 
            }
            if k == 0 {
                break;
            }
            k -= 1;
        } 
        res
    }
}
// @lc code=end

/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */
