/*
 * @lc app=leetcode.cn id=630 lang=rust
 *
 * [630] 课程表 III
 *
 * https://leetcode.cn/problems/course-schedule-iii/description/
 *
 * algorithms
 * Hard (46.13%)
 * Likes:    525
 * Dislikes: 0
 * Total Accepted:    38.5K
 * Total Submissions: 80.9K
 * Testcase Example:  '[[100,200],[200,1300],[1000,1250],[2000,3200]]'
 *
 * 这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中 courses[i] = [durationi,
 * lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。
 *
 * 你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。
 *
 * 返回你最多可以修读的课程数目。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
 * 输出：3
 * 解释：
 * 这里一共有 4 门课程，但是你最多可以修 3 门：
 * 首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
 * 第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
 * 第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
 * 第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。
 *
 * 示例 2：
 *
 *
 * 输入：courses = [[1,2]]
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：courses = [[3,2],[4,3]]
 * 输出：0
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= courses.length <= 10^4
 * 1 <= durationi, lastDayi <= 10^4
 *
 *
 */

// @lc code=start
impl Solution {
    pub fn schedule_course(mut courses: Vec<Vec<i32>>) -> i32 {
        // 贪心算法： 按 deadline 排序，然后按 duration 从小到大选课
        // 若选了某课程，但是超过了 deadline，那么就把之前选的 duration(courses[0]) 最大的课程去掉
        courses.sort_by_key(|v| v[1]);
        let mut heap = std::collections::BinaryHeap::new();
        let mut total_time = 0;
        for course in courses.iter() {
            heap.push(course[0]);
            total_time += course[0];
            if total_time > course[1] {
                if let Some(max_duration) = heap.pop() {
                    total_time -= max_duration;
                }
            }
        }
        heap.len() as i32
    }
}
// @lc code=end
