/*
 * @lc app=leetcode.cn id=3046 lang=rust
 * @lcpr version=30204
 *
 * [3046] 分割数组
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn is_possible_to_split(nums: Vec<i32>) -> bool {
        let mut map: HashMap<i32, usize> = HashMap::new();
        for num in nums {
            *map.entry(num).or_insert(0) += 1;
        }
        map.into_values().all(|x| x <= 2)
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1]\n
// @lcpr case=end

 */

