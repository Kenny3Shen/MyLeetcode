/*
 * @lc app=leetcode.cn id=3242 lang=rust
 * @lcpr version=30204
 *
 * [3242] 设计相邻元素求和服务
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
use std::collections::HashMap;

const dirs: [ &[(i32, i32)]; 2] = [
    &[(-1, 0), (1, 0), (0, -1), (0, 1)],   
    &[(-1, -1), (-1, 1), (1, -1), (1, 1)],
];

struct NeighborSum {
    grid: Vec<Vec<i32>>,
    pos: HashMap<i32, (usize, usize)>,
}

impl NeighborSum {

    fn new(grid: Vec<Vec<i32>>) -> Self {
        let mut pos = HashMap::new();
        for (i, row) in grid.iter().enumerate() {
            for (j, &val) in row.iter().enumerate() {
                pos.insert(val, (i, j));
            }
        }
        NeighborSum { grid, pos }
    }
    
    fn adjacent_sum(&self, value: i32) -> i32 {
        self.get_sum(value, 0)
    }
    
    fn diagonal_sum(&self, value: i32) -> i32 {
        self.get_sum(value, 1)
    }

    fn get_sum(&self, value: i32, idx: usize) -> i32 {
        if let Some(&(x, y)) = self.pos.get(&value) {
            let mut sum = 0;
            for &(dx, dy) in dirs[idx] {
                let nx = x as i32 + dx;
                let ny = y as i32 + dy;
                if nx >= 0 && (nx as usize) < self.grid.len() && ny >= 0 && (ny as usize) < self.grid[0].len() {
                    sum += self.grid[nx as usize][ny as usize];
                }
            }
            sum
        } else {
            0
        }
    }
}

// /**
//  * Your NeighborSum object will be instantiated and called as such:
//  * let obj = NeighborSum::new(grid);
//  * let ret_1: i32 = obj.adjacent_sum(value);
//  * let ret_2: i32 = obj.diagonal_sum(value);
//  */
// @lc code=end



/*
// @lcpr case=start
// ["neighborSum", "adjacentSum", "adjacentSum", "diagonalSum", "diagonalSum"][[[[0, 1, 2], [3, 4, 5], [6, 7, 8]]], [1], [4], [4], [8]]\n
// @lcpr case=end

// @lcpr case=start
// ["neighborSum", "adjacentSum", "diagonalSum"][[[[1, 2, 0, 3], [4, 7, 15, 6], [8, 9, 10, 11], [12, 13, 14, 5]]], [15], [9]]\n
// @lcpr case=end

 */

