/*
 * @lc app=leetcode.cn id=3000 lang=rust
 * @lcpr version=30204
 *
 * [3000] 对角线最长的矩形的面积
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn area_of_max_diagonal(mut dimensions: Vec<Vec<i32>>) -> i32 {
        // dimensions.sort_by(|a: &Vec<i32>, b: &Vec<i32>| {
        //     let diag_a = a[0] * a[0] + a[1] * a[1];
        //     let diag_b = b[0] * b[0] + b[1] * b[1];
        //     if diag_a == diag_b {
        //         (a[0] * a[1]).cmp(&(b[0] * b[1]))
        //     } else {
        //         diag_a.cmp(&diag_b)
        //     }
        // });

        // dimensions[dimensions.len() - 1][0] * dimensions[dimensions.len() - 1][1]
        dimensions
            .iter()
            .fold((0, 0), |acc, d| {
                match (
                    d[0] * d[0] + d[1] * d[1] > acc.0,
                    d[0] * d[0] + d[1] * d[1] == acc.0,
                    d[0] * d[1] > acc.1,
                ) {
                    (true, _, _) => (d[0] * d[0] + d[1] * d[1], d[0] * d[1]),
                    (false, true, true) => (acc.0, d[0] * d[1]),
                    (_, _, _) => acc,
                }
            })
            .1 // 方法返回一个元组 (max_diagonal, max_area)，最后使用 .1 提取面积。
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[9,3],[8,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,4],[4,3]]\n
// @lcpr case=end

 */
