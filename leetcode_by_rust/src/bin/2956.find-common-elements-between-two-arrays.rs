/*
 * @lc app=leetcode.cn id=2956 lang=rust
 * @lcpr version=30204
 *
 * [2956] 找到两个数组中的公共元素
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
use std::collections::HashSet;
impl Solution {
    pub fn find_intersection_values(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut s1 = HashSet::new();
        let mut s2 = HashSet::new();
        for x in nums1.iter() {
            s1.insert(x);
        }
        for x in nums2.iter() {
            s2.insert(x);   
        }
        let mut res1 = 0;
        let mut res2 = 0;
        for x in nums1.iter() {
            if s2.contains(x) {
                res1 += 1;
            }
        }
        for x in nums2.iter() {
            if s1.contains(x) {
                res2 += 1;
            }
        }
        [res1, res2].to_vec()
    }
}
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n[1,2]\n
// @lcpr case=end

// @lcpr case=start
// [4,3,2,3,1]\n[2,2,5,2,3,6]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,2,3]\n[1,5]\n
// @lcpr case=end

 */

