/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (40.34%)
 * Likes:    593
 * Dislikes: 0
 * Total Accepted:    133.3K
 * Total Submissions: 330.4K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findFirst(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                // ① 不可以直接返回，应该继续向左边找，即 [left, mid - 1] 区间里找
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                // 应该继续向右边找，即 [mid + 1, right] 区间里找
                left = mid + 1;
            }
            else
            {
                // 此时 nums[mid] > target，应该继续向左边找，即 [left, mid - 1] 区间里找
                right = mid - 1;
            }
        }

        // 此时 left 和 right 的位置关系是 [right, left]，注意上面的 ①，此时 left 才是第 1 次元素出现的位置
        // 因此还需要特别做一次判断
        if (left != nums.size() && nums[left] == target)
            return left;

        return -1;
    }

    int findLast(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                // 只有这里不一样：不可以直接返回，应该继续向右边找，即 [mid + 1, right] 区间里找
                left = mid + 1;
            }
            else if (nums[mid] < target)
            {
                // 应该继续向右边找，即 [mid + 1, right] 区间里找
                left = mid + 1;
            }
            else
            {
                // 此时 nums[mid] > target，应该继续向左边找，即 [left, mid - 1] 区间里找
                right = mid - 1;
            }
        }
        if (right != -1 && nums[right] == target)
            return right;

        return -1;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return vector<int>{-1, -1};

        int firstPosition = findFirst(nums, target);
        /* // 如果第 1 次出现的位置都找不到，肯定不存在最后 1 次出现的位置
        if (firstPosition == -1)
        {
            return vector<int>{-1, -1};
        } */
        int lastPosition = findLast(nums, target);
        return vector<int>{firstPosition, lastPosition};
    }
};
// @lc code=end
