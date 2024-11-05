/*
 * @lc app=leetcode.cn id=3254 lang=rust
 * @lcpr version=30204
 *
 * [3254] 长度为 K 的子数组的能量值 I
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn results_array(nums: Vec<i32>, k: i32) -> Vec<i32> {
        fn get_power(sub: &[i32]) -> i32 {
            let n = sub.len();
            for i in 1..n {
                if sub[i] - sub[i - 1] != 1{
                    return -1;
                }
            }
            return sub[n - 1];
        }
        let sub_k = nums.windows(k as usize);
        let mut res = vec![];
        for sub in sub_k {
            res.push(get_power(sub));
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,3,2,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [3,2,3,2,3,2]\n2\n
// @lcpr case=end

 */

