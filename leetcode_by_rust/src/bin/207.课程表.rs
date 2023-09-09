/*
 * @lc app=leetcode.cn id=207 lang=rust
 *
 * [207] 课程表
 *
 * https://leetcode.cn/problems/course-schedule/description/
 *
 * algorithms
 * Medium (53.59%)
 * Likes:    1736
 * Dislikes: 0
 * Total Accepted:    328.5K
 * Total Submissions: 611.3K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 * 
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi]
 * ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
 * 
 * 
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 * 
 * 
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：true
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 * 
 * 示例 2：
 * 
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * prerequisites[i] 中的所有课程对 互不相同
 * 
 * 
 */


// @lc code=start
use std::collections::{HashMap, VecDeque};
impl Solution {
    pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
        let num_courses: usize = num_courses as usize;
        let mut in_degree: Vec<i32> = vec![0; num_courses];
        // let mut adjacent: HashMap<i32, Vec<i32>> = HashMap::new();
        let mut adjacent = vec![vec![]; num_courses];
        let mut finished: usize = 0;
        for prerequisite in prerequisites.iter() {
            let to = prerequisite[0] as usize; 
            let from = prerequisite[1] as usize;
            in_degree[to as usize] += 1;
            adjacent[from].push(to);
            // (adjacent.entry(from).or_insert(vec![])).push(to);
        }
        let mut can_out = VecDeque::new();
        for i in 0..num_courses {
            if in_degree[i] == 0 {
                can_out.push_back(i as usize);
            }
        }
        while !can_out.is_empty() {
            let n = can_out.len();
            for i in 0..n {
                let out = can_out.pop_front().unwrap();
                finished += 1;
                for to in adjacent[out].iter() {
                    in_degree[*to as usize] -= 1;
                    if in_degree[*to as usize] == 0 {
                        can_out.push_back(*to);
                    }
                }
                // for to in adjacent.get(&out).unwrap_or(&vec![]).iter() {
                //     in_degree[*to as usize] -= 1;
                //     if in_degree[*to as usize] == 0 {
                //         can_out.push_back(*to);
                //     }
                // }
            }
        }
        finished == num_courses
    }
}
// @lc code=end

