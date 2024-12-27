/*
 * @lc app=leetcode.cn id=3142 lang=rust
 * @lcpr version=30204
 *
 * [3142] 判断矩阵是否满足条件
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn satisfies_conditions(grid: Vec<Vec<i32>>) -> bool {
        let (row, col) = (grid.len(), grid[0].len());
        for i in 0..row {
            for j in 0..col {
                if i + 1 < row {
                    if grid[i + 1][j] != grid[i][j] {
                        return false;
                    }
                };
                if j + 1 < col {
                    if grid[i][j + 1] == grid[i][j] {
                        return false;
                    }
                };
            }
        }
        true
    }
}
// @lc code=end



/*
// @lcpr case=start
// [[1,0,2],[1,0,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1],[0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[2],[3]]\n
// @lcpr case=end

 */

