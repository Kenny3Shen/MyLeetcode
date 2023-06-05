/*
 * @lc app=leetcode.cn id=1130 lang=rust
 *
 * [1130] 叶值的最小代价生成树
 *
 * https://leetcode.cn/problems/minimum-cost-tree-from-leaf-values/description/
 *
 * algorithms
 * Medium (64.87%)
 * Likes:    363
 * Dislikes: 0
 * Total Accepted:    19K
 * Total Submissions: 27K
 * Testcase Example:  '[6,2,4]'
 *
 * 给你一个正整数数组 arr，考虑所有满足以下条件的二叉树：
 * 
 * 
 * 每个节点都有 0 个或是 2 个子节点。
 * 数组 arr 中的值与树的中序遍历中每个叶节点的值一一对应。
 * 每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。
 * 
 * 
 * 在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。这个和的值是一个 32 位整数。
 * 
 * 如果一个节点有 0 个子节点，那么该节点为叶节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr = [6,2,4]
 * 输出：32
 * 解释：有两种可能的树，第一种的非叶节点的总和为 36 ，第二种非叶节点的总和为 32 。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：arr = [4,11]
 * 输出：44
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= arr.length <= 40
 * 1 <= arr[i] <= 15
 * 答案保证是一个 32 位带符号整数，即小于 2^31 。
 * 
 * 
 */


// @lc code=start
use std::cmp::min;
impl Solution {
    pub fn mct_from_leaf_values(arr: Vec<i32>) -> i32 {
        let mut st:Vec<i32> = Vec::with_capacity(arr.len());
        st.push(i32::MAX);
        let mut res = 0i32;
        for i in arr.iter() {
            while i >= st.last().unwrap() {
                res += st.pop().unwrap() * min(st.last().unwrap(), i);
            }
            st.push(*i);
        }
        while st.len() > 2 {
            res += st.pop().unwrap() * st.last().unwrap();
        }
        res
    }
}
// @lc code=end

