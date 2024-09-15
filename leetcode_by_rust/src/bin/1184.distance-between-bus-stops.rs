/*
 * @lc app=leetcode.cn id=1184 lang=rust
 * @lcpr version=30204
 *
 * [1184] 公交站间的距离
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn distance_between_bus_stops(distance: Vec<i32>, start: i32, destination: i32) -> i32 {
        let (mut start, mut destination) = (start as usize, destination as usize);
        if start > destination {
            (start, destination) = (destination, start);
        }
        let start_to_dest = distance[start..destination].iter().sum::<i32>();
        let dest_to_start = distance[destination..].iter().sum::<i32>() + distance[..start].iter().sum::<i32>();
        start_to_dest.min(dest_to_start)
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4]\n0\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n0\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n0\n3\n
// @lcpr case=end

 */

