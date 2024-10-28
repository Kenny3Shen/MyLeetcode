/*
 * @lc app=leetcode.cn id=3211 lang=rust
 * @lcpr version=30204
 *
 * [3211] 生成不含相邻零的二进制字符串
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn valid_strings(n: i32) -> Vec<String> {
        let mut res = vec![];
        let mut path = vec![];
        Self::dfs(&mut path, n as usize, &mut res);
        res
    }

    fn dfs(path: &mut Vec<char>, n : usize, res: &mut Vec<String>) {
        if path.len() == n {
            res.push(path.iter().collect());
            return;
        }
        if path.is_empty() || path[path.len() - 1] == '1' {
            path.push('0');
            Self::dfs(path, n, res);
            path.pop();
        }
        path.push('1');
        Self::dfs(path, n, res);
        path.pop();
    }
}
// @lc code=end



/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

