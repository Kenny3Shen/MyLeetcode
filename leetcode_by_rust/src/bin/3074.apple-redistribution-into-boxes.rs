/*
 * @lc app=leetcode.cn id=3074 lang=rust
 * @lcpr version=30204
 *
 * [3074] 重新分装苹果
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn minimum_boxes(mut apple: Vec<i32>, mut capacity: Vec<i32>) -> i32 {
        let all_apples = apple.iter().sum();
        capacity.sort();
        let mut res = 0;
        let mut cur_capacity = 0;
        loop {
            cur_capacity += capacity.pop().unwrap();
            res += 1;
            if cur_capacity >= all_apples {
                break res;
            }
        }
            
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,3,2]\n[4,3,1,5,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5]\n[2,4,2,7]\n
// @lcpr case=end

 */

