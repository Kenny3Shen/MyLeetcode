/*
 * @lc app=leetcode.cn id=825 lang=rust
 * @lcpr version=30204
 *
 * [825] 适龄的朋友
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn num_friend_requests(ages: Vec<i32>) -> i32 {
        let mut cnt = vec![0; 121];
        for age in ages {
            cnt[age as usize] += 1;
        }

        let mut ans = 0;
        let mut age_y = 0;
        let mut cnt_window = 0;
        for age_x in 0..cnt.len() {
            cnt_window += cnt[age_x];
            if age_y * 2 <= age_x + 14 { // 不能发送好友请求
                cnt_window -= cnt[age_y];
                age_y += 1;
            }
            if cnt_window > 0 { // 存在可以发送好友请求的用户
                ans += cnt[age_x] * cnt_window - cnt[age_x];
            }
        }
        ans
    }
}
// @lc code=end



/*
// @lcpr case=start
// [16,16]\n
// @lcpr case=end

// @lcpr case=start
// [16,17,18]\n
// @lcpr case=end

// @lcpr case=start
// [20,30,100,110,120]\n
// @lcpr case=end

 */

