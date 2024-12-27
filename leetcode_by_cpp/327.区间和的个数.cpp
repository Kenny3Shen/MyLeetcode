/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 *
 * https://leetcode-cn.com/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (36.79%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 16.2K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * 给定一个整数数组 nums，返回区间和在 [lower, upper] 之间的个数，包含 lower 和 upper。
 * 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
 * 
 * 说明:
 * 最直观的算法复杂度是 O(n^2) ，请在此基础上优化你的算法。
 * 
 * 示例:
 * 
 * 输入: nums = [-2,5,-1], lower = -2, upper = 2,
 * 输出: 3 
 * 解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {
        int size = nums.size();
        if (size == 0)
            return 0;
        vector<long long> presum; //前缀和数组， [0,i] 区间和
        long long pre = 0;
        for (auto &num : nums)
        {
            pre += num;
            presum.emplace_back(pre);
        }
        int result = 0;
        vector<long long> temp(size); //用于合并两个有序数组的临时数组
        mergesort(presum, lower, upper, temp, 0, size - 1, result);
        return result;
    }
    void mergesort(vector<long long> &presum, int lower, int upper, vector<long long> &temp, int left, int right, int &result)
    {
        if (left == right) //分到只剩一个元素
        {
            if (presum[left] >= lower && presum[left] <= upper)
            {
                result++;
            }
            return;
        }
        int mid = left + (right - left) / 2;
        mergesort(presum, lower, upper, temp, left, mid, result);      //使 [left,mid] 有序
        mergesort(presum, lower, upper, temp, mid + 1, right, result); //使 [mid+1,right] 有序
        //合并之前先统计
        int i = left; // i 指向左区间
        int j_left = mid + 1;
        int j_right = mid + 1; // j_left、j_right 指向右区间，i < j，相减得到区间和
        while (i < mid + 1)    // i 固定时，j 越大差越大；j  固定时，i 越大差越小
        {
            while (j_left <= right && presum[j_left] - presum[i] < lower) //找到下限位置
            {
                j_left++;
            }
            j_right = j_left;
            while (j_right <= right && presum[j_right] - presum[i] <= upper) //找到上限位置
            {
                j_right++;
                result++; //找到一对
            }
            i++;
        }
        //合并
        i = left;
        int j = mid + 1;
        int t = 0;
        while (i <= mid && j <= right)
        {
            if (presum[i] <= presum[j])
            {
                temp[t++] = presum[i++];
            }
            else
            {
                temp[t++] = presum[j++];
            }
        }
        while (i <= mid)
        {
            temp[t++] = presum[i++];
        }
        while (j <= right)
        {
            temp[t++] = presum[j++];
        }
        t = 0;
        i = left;
        while (i <= right)
        {
            presum[i++] = temp[t++];
        }
    }
};

// @lc code=end
