/*
 * @lc app=leetcode.cn id=2965 lang=rust
 * @lcpr version=30204
 *
 * [2965] 找出缺失和重复的数字
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn find_missing_and_repeated_values(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n = grid.len();
        let (mut map, mut res) = (vec![0; n * n + 1], vec![0; 2]);
        grid.iter()
            .for_each(|row| row.iter().for_each(|&x| map[x as usize] += 1));
        map.into_iter()
            .enumerate()
            .for_each(|(i, x)| {
               match x {
                   2 => res[0] = i as i32,
                   0 => res[1] = i as i32,
                   _ => {}
            }
        });
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[9,1,7],[8,9,2],[3,4,6]]\n
// @lcpr case=end

 */

