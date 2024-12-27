/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.52%)
 * Likes:    1870
 * Dislikes: 0
 * Total Accepted:    737.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 *
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: [3,2,1,5,6,4], k = 2
 * 输出: 5
 *
 *
 * 示例 2:
 *
 *
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4
 * 输出: 4
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int len = nums.size();
        int tar = len - k;
        int left = 0, right = len - 1;
        while (true)
        {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == tar)
                return nums[pivotIndex];
            else if (pivotIndex < tar)
                left = pivotIndex + 1;
            else
                right = pivotIndex - 1;
        }
        return 0;
    }

    int partition(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return left;
        int randomIndex = left + rand() % (right - left + 1);
        swap(nums[left], nums[randomIndex]);
        int pivot = nums[left];
        while (left < right)
        {
            while (left < right && nums[right] >= pivot)
                right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivot)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot; //left == right 确定pivot的位置
        return left;
    }
};
// @lc code=end
