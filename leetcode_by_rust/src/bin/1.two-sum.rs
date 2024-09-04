/*
 * @lc app=leetcode.cn id=1 lang=rust
 * @lcpr version=30204
 *
 * [1] 两数之和
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = std::collections::HashMap::new();
        for (i, &num) in nums.iter().enumerate() {
            match map.get(&(target - num)) {
                Some(&j) => return vec![j as i32, i as i32],
                None => {
                    map.insert(num, i);
                }
            }
        }
        vec![]
    }
}
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */

