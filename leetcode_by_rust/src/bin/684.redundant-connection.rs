/*
 * @lc app=leetcode.cn id=684 lang=rust
 * @lcpr version=30204
 *
 * [684] 冗余连接
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let mut uf = UnionFind::new(edges.len());

        for edge in edges {
            if uf.union(edge[0] as usize - 1, edge[1] as usize - 1) {
                return edge;
            }
        }

        vec![]
    }
}

struct UnionFind {
    parent: Vec<usize>,
    cnt: usize,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let parent = (0..n).collect();

        UnionFind { parent, cnt: n }
    }

    fn find(&mut self, i: usize) -> usize {
        if i != self.parent[i] {
            self.parent[i] = self.find(self.parent[i]);
        }

        self.parent[i]
    }

    fn union(&mut self, i: usize, j: usize) -> bool {
        let x = self.find(i);
        let y = self.find(j);

        if x == y {
            true
        } else {
            self.parent[x] = y;
            false
        }
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[1,2], [1,3], [2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2], [2,3], [3,4], [1,4], [1,5]]\n
// @lcpr case=end

 */
