/*
 * @lc app=leetcode.cn id=4 lang=rust
 * @lcpr version=30204
 *
 * [4] 寻找两个正序数组的中位数
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let min_left = (nums1.len() + nums2.len() + 1) / 2;
        let min_right = (nums1.len() + nums2.len() + 2) / 2;
        let mut res: f64 = 0f64;
    
        let mut i = 0;
        let mut j = 0;
        let mut cur: i32 = 0;
        while i < nums1.len() || j < nums2.len() {
            // 如果第二个数组已经遍历完，只能选择第一个数组
            if j == nums2.len() || (i < nums1.len() && nums1[i] < nums2[j]) {
                cur = nums1[i];
                i += 1;
            } else {
                cur = nums2[j];
                j += 1;
            }
    
            if i + j == min_left {
                res += cur as f64;
            }
            if i + j == min_right {
                res += cur as f64;
            }
        }
        res / 2.0
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

