/*
 * @lc app=leetcode.cn id=2748 lang=rust
 * @lcpr version=30204
 *
 * [2748] 美丽下标对的数目
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn count_beautiful_pairs(nums: Vec<i32>) -> i32 {
        fn gcd(x1: i32, x2: i32) -> i32 {
            if x1 == 0 {
                return x2;
            }
            return gcd(x2 % x1, x1);
        }
        let mut res = 0;
        let n = nums.len();
        for i in 0..n {
            for j in i + 1..n {
                // 获取最高位数字
                let mut t = nums[i];
                let x = loop {
                    let x = t / 10;
                    if x == 0 {
                        break t;
                    } else {
                        t = x;
                    }
                };
                let y = nums[j] % 10;
                if gcd(x, y) == 1 {
                    res += 1;
                }
            }
        }
        res
    }
}
// @lc code=end

/*
// @lcpr case=start
// [2,5,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [11,21,12]\n
// @lcpr case=end

 */
