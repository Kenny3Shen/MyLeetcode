#
# @lc app=leetcode.cn id=815 lang=python3
# @lcpr version=30204
#
# [815] 公交路线
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        stop_to_routes = defaultdict(list)
        for i, route in enumerate(routes):
            for stop in route:
                stop_to_routes[stop].append(i)
        visited = [False] * len(routes)
        queue = deque()
        for route in stop_to_routes[source]:
            visited[route] = True
            queue.append((route, 1))
        while len(queue) > 0:
            route, step = queue.popleft()
            for stop in routes[route]:
                if stop == target:
                    return step
                for next_route in stop_to_routes[stop]:
                    if not visited[next_route]:
                        visited[next_route] = True
                        queue.append((next_route, step + 1))
        return -1

# @lc code=end



#
# @lcpr case=start
# [[1,2,7],[3,6,7]]\n1\n6\n
# @lcpr case=end

# @lcpr case=start
# [[7,12],[4,5,15],[6],[15,19],[9,12,13]]\n15\n12\n
# @lcpr case=end

#

