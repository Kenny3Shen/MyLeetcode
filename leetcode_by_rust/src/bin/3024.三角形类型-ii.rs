/*
 * @lc app=leetcode.cn id=3024 lang=rust
 *
 * [3024] 三角形类型 II
 */

// @lc code=start
impl Solution {
    pub fn triangle_type(mut nums: Vec<i32>) -> String {
        nums.sort();
        let (a, b, c) = (nums[0], nums[1], nums[2]);
        if a + b <= c {
            return "none".to_string();
        }
        if a == b && b == c {
            return "equilateral".to_string();
        }
        if a == b || b == c {
            return "isosceles".to_string();
        }
        "scalene".to_string()
    }
}
// @lc code=end

