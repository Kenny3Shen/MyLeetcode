/*
 * @lc app=leetcode.cn id= 面试题 04.01 lang=rust
 * @lcpr version=30204
 *
 * [ 面试题 04.01] 节点间通路
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn find_whether_exists_path(n: i32, graph: Vec<Vec<i32>>, start: i32, target: i32) -> bool {
        if n == 0 {
            return false;
        }
        if start == target {
            return true;
        }
        let mut vec  = vec![std::collections::HashSet::new(); n as usize];
        for edge in graph.iter() {
            vec[edge[0] as usize].insert(edge[1]);
        }

        fn bfs(n: i32, vec: &Vec<std::collections::HashSet<i32>>, start: i32, target: i32) -> bool {
            let mut visited = vec![false; n as usize];
            let mut queue = std::collections::VecDeque::new();
            queue.push_back(start);
            visited[start as usize] = true;
            while !queue.is_empty() {
                let node = queue.pop_front().unwrap();
                for &next in vec[node as usize].iter() {
                    if next == target {
                        return true;
                    }
                    if !visited[next as usize] {
                        queue.push_back(next);
                        visited[next as usize] = true;
                    }
                }
            }
            false
        }
        bfs(n, &vec, start, target)
    }
}
// @lc code=end



/*
// @lcpr case=start
// 3\n[[0, 1], [0, 2], [1, 2], [1, 2]]\n0\n2\n
// @lcpr case=end

 */

