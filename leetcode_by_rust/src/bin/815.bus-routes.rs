/*
 * @lc app=leetcode.cn id=815 lang=rust
 * @lcpr version=30204
 *
 * [815] 公交路线
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn num_buses_to_destination(routes: Vec<Vec<i32>>, source: i32, target: i32) -> i32 {
        if source == target {
            return 0;
        }
        let mut stop_to_routes = std::collections::HashMap::new();
        
        // 站点 stop 可以在第 i 条公交线路上
        for (i, route) in routes.iter().enumerate() {
            for stop in route.iter() {
                stop_to_routes.entry(stop).or_insert(vec![]).push(i);
            }
        }
        let mut visited = vec![false; routes.len()];
        let mut queue = std::collections::VecDeque::new();
        for route in stop_to_routes.get(&source).unwrap_or(&vec![]) {
            visited[*route] = true;
            queue.push_back((*route, 1));
        }
        while !queue.is_empty() {
            let (route, step) = queue.pop_front().unwrap();
            for stop in routes[route].iter() {
                if *stop == target {
                    return step;
                }
                for next_route in stop_to_routes.get(stop).unwrap_or(&vec![]) {
                    if !visited[*next_route] {
                        visited[*next_route] = true;
                        queue.push_back((*next_route, step + 1));
                    }
                }
            }
        }
        -1
    }
}
// @lc code=end



/*
// @lcpr case=start
// [[1,2,7],[3,6,7]]\n1\n6\n
// @lcpr case=end

// @lcpr case=start
// [[7,12],[4,5,15],[6],[15,19],[9,12,13]]\n15\n12\n
// @lcpr case=end

 */

