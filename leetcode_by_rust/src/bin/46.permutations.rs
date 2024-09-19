/*
 * @lc app=leetcode.cn id=46 lang=rust
 * @lcpr version=30204
 *
 * [46] 全排列
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        // fn backtrack(nums: &Vec<i32>, path: &mut Vec<i32>, used: &mut Vec<bool>, res: &mut Vec<Vec<i32>>) {
        //     if path.len() == nums.len() {
        //         res.push(path.clone());
        //         return;
        //     }
        //     for i in 0..nums.len() {
        //         if used[i] {
        //             continue;
        //         }
        //         used[i] = true;
        //         path.push(nums[i]);
        //         backtrack(nums, path, used, res);
        //         path.pop();
        //         used[i] = false;
        //     }
        // }
        // let mut res = vec![];
        // let mut path = vec![];
        // let mut used = vec![false; nums.len()];
        // backtrack(&nums, &mut path, &mut used, &mut res);
        // res
        
        fn backtrack(nums: &mut Vec<i32>, first: usize, n: usize, res: &mut Vec<Vec<i32>>) {
            if first == n {
                res.push(nums.clone());
                return;
            }
            for i in first..n {
                nums.swap(first, i);
                backtrack(nums, first + 1, n, res);
                nums.swap(first, i);
            }
        }

        let n = nums.len();
        let capacity = (1..=n).product();
        let mut res = Vec::with_capacity(capacity);
        let mut nums = nums;
        backtrack(&mut nums, 0, n, &mut res);
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

