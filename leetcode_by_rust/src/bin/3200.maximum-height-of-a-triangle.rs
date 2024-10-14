/*
 * @lc app=leetcode.cn id=3200 lang=rust
 * @lcpr version=30204
 *
 * [3200] 三角形的最大高度
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn max_height_of_triangle(red: i32, blue: i32) -> i32 {
        fn get_max_height(mut x: i32, mut y: i32) -> i32 {
            let mut start = 1;
            loop { // loop can return value by break
                match start % 2 {
                    1 => x -= start,
                    0 => y -= start,
                    _ => unreachable!("mod 2 can not reach here!"),
                }
                if x < 0 || y < 0 {
                    break start - 1;
                }
                start += 1;
            }
            // start - 1
        }
        std::cmp::max(get_max_height(red, blue), get_max_height(blue, red))

        // fn get_max_height(x: i32, y: i32) -> i32 {
        //     let odd = 2 * ((x as f64).sqrt() as i32) - 1;
        //     let even = 2 * (((-1.0 + (1.0 + 4.0 * (y as f64)).sqrt()) / 2.0) as i32);
        //     odd.min(even) + 1
        // }

        // std::cmp::max(get_max_height(red, blue), get_max_height(blue, red))
    }
}
// @lc code=end



/*
// @lcpr case=start
// 2\n4\n
// @lcpr case=end

// @lcpr case=start
// 2\n1\n
// @lcpr case=end

// @lcpr case=start
// 1\n1\n
// @lcpr case=end

// @lcpr case=start
// 10\n1\n
// @lcpr case=end

 */

