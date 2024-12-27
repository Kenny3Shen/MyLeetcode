/*
 * @lc app=leetcode.cn id=3145 lang=rust
 * @lcpr version=30204
 *
 * [3145] 大数组元素的乘积
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn find_products_of_elements(queries: Vec<Vec<i64>>) -> Vec<i32> {
        let mut res = vec![];
        for query in queries {
            let mut product = 1;
            for num in query {
                product *= num;
            }
            res.push(product as i32);
        }
        res
    }
}
// @lc code=end



/*
// @lcpr case=start
// [[1,3,7]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,5,3],[7,7,4]]\n
// @lcpr case=end

 */

