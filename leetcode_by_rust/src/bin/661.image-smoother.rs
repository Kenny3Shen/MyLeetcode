/*
 * @lc app=leetcode.cn id=661 lang=rust
 * @lcpr version=30204
 *
 * [661] 图片平滑器
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn image_smoother(img: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (m, n) = (img.len(), img[0].len());
        let mut ret = vec![vec![0; n]; m];

        for i in 0..m {
            for j in 0..n {
                let (mut sum, mut cnt) = (0, 0);
                for &r in &[i - 1, i, i + 1] {
                    for &c in &[j - 1, j, j + 1] {
                        if r >= m || c >= n {
                            continue;
                        }
                        sum += img[r][c];
                        cnt += 1;
                    }
                }
                ret[i][j] = sum / cnt;
            }
        }
        ret
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[1,1,1],[1,0,1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[100,200,100],[200,50,200],[100,200,100]]\n
// @lcpr case=end

 */
