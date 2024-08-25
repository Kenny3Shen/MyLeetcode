/*
 * @lc app=leetcode.cn id=698 lang=rust
 * @lcpr version=30204
 *
 * [698] 划分为 k 个相等的子集
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn can_partition_k_subsets(mut nums: Vec<i32>, k: i32) -> bool {
        fn back_trace(
            nums: &mut Vec<i32>,
            buckets: &mut Vec<i32>,
            start: i32,
            target: i32,
        ) -> bool {
            if start < 0 {
                return true;
            }
            let mut num = nums[start as usize];
            for i in 0..buckets.len() {
                if num + buckets[i] <= target {
                    buckets[i] += num;
                    if back_trace(nums, buckets, start - 1, target) {
                        return true;
                    }
                    buckets[i] -= num;
                }
                if buckets[i] == 0 {
                    break;
                }
            }
            false
        }
        let (sum, n) = (nums.iter().sum::<i32>(), nums.len() as i32);
        nums.sort();
        if sum % k != 0 || sum / k < nums[0] || sum / k < nums[n as usize - 1] {
            return false;
        }
        back_trace(&mut nums, &mut vec![0; k as usize], n - 1, sum / k)
    }
}
// @lc code=end

/*
// @lcpr case=start
// [4, 3, 2, 3, 5, 2, 1]\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n3\n
// @lcpr case=end

 */
