/*
 * @lc app=leetcode.cn id=540 lang=rust
 * @lcpr version=30204
 *
 * [540] 有序数组中的单一元素
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        // let mut res = 0;
        // for num in nums {
        //     res ^= num;
        // }
        // res
        
        // 成对出现的两个元素中，第一个总是在偶数索引位置，第二个总是在奇数索引位置，当单个元素出现时，将错过该匹配，由此实现算法。
        let (mut left, mut right) = (0, nums.len() as i32 - 1);
        while left < right {
            let m = left + (right - left) / 2;
            if m % 2 == 1 {
                if nums[m as usize] == nums[m as usize - 1] {
                    left = m + 1;
                } else {
                    right = m - 1;
                }
            } else {
                if nums[m as usize] == nums[m as usize + 1] {
                    left = m + 2;
                } else {
                    right = m;
                }
            }
        }
        nums[left as usize]
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,3,3,4,4,8,8]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,7,7,10,11,11]\n
// @lcpr case=end

 */

