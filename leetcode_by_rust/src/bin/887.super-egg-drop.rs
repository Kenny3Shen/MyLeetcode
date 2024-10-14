/*
 * @lc app=leetcode.cn id=887 lang=rust
 * @lcpr version=30204
 *
 * [887] 鸡蛋掉落
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn super_egg_drop(k: i32, n: i32) -> i32{
        let mut memo: std::collections::HashMap<i32, i32> = std::collections::HashMap::new();
        fn dp(k: i32, n: i32) -> i32 {
            let mut ans = 0;
            if n == 0 {
                ans = 0;
            } else if k == 1 {
                ans = n;
            } else {
                let mut lo = 1;
                let mut hi = n;
                while lo + 1 < hi {
                    let x = (lo + hi) / 2;
                    let t1 = dp(k - 1, x - 1);
                    let t2 = dp(k, n - x);
                    if t1 < t2 {
                        lo = x;
                    } else if t1 > t2 {
                        hi = x;
                    } else {
                        lo = x;
                        hi = x;
                    }
                }

                ans = 1 + std::cmp::min(
                    std::cmp::max(dp(k - 1, lo - 1), dp(k, n - lo)),
                    std::cmp::max(dp(k - 1, hi - 1), dp(k, n - hi)),
                );
            }
            memo[n * 100 + k] = ans;

            memo[n * 100 + k]
        }
        dp(k, n)
    }
}
// @lc code=end

/*
// @lcpr case=start
// 1\n2\n
// @lcpr case=end

// @lcpr case=start
// 2\n6\n
// @lcpr case=end

// @lcpr case=start
// 3\n14\n
// @lcpr case=end

 */
