/*
 * @lc app=leetcode.cn id=2848 lang=rust
 * @lcpr version=30204
 *
 * [2848] 与车相交的点
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn number_of_points(nums: Vec<Vec<i32>>) -> i32 {
        let mut C = 0;
        for interval in &nums {
            C = C.max(interval[1]);
        }

        let mut diff = vec![0; (C + 2) as usize];
        for interval in &nums {
            diff[interval[0] as usize] += 1;
            diff[(interval[1] + 1) as usize] -= 1;
        }

        let mut ans = 0;
        let mut count = 0;
        for i in 1..=C {
            count += diff[i as usize];
            if count > 0 {
                ans += 1;
            }
        }

        ans
    }
}
// @lc code=end



/*
// @lcpr case=start
// [[3,6],[1,5],[4,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[5,8]]\n
// @lcpr case=end

 */

