/*
 * @lc app=leetcode.cn id=56 lang=rust
 * @lcpr version=30204
 *
 * [56] 合并区间
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        // intervals.sort_by_key(|x| x[0]);
        // let mut res = vec![];
        // for i in 1..intervals.len() {
        //     if intervals[i][0] <= intervals[i - 1][1] {
        //         intervals[i][0] = intervals[i - 1][0];
        //         intervals[i][1] = intervals[i][1].max(intervals[i - 1][1]);
        //     } else {
        //         res.push(intervals[i - 1].clone());
        //     }
        // }
        // res.push(intervals[intervals.len() - 1].clone());
        // res

        let mut intervals = intervals;
        intervals.sort_by_key(|x| x[0]);

        let mut res: Vec<Vec<i32>> = Vec::new();

        for interval in intervals {
            if res.is_empty() || res.last().unwrap()[1] < interval[0] {
                res.push(interval);
            } else {
                let last = res.last_mut().unwrap();
                last[1] = last[1].max(interval[1]);
            }
        }

        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */

