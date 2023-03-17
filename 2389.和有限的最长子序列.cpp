/*
 * @lc app=leetcode.cn id=2389 lang=cpp
 *
 * [2389] 和有限的最长子序列
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    void quick_sort(vector<int> &nums, int left, int right)
    {
        if (left < right)
        {
            int l = left, r = right;
            int pivot = nums[left];
            while (l < r)
            {
                while (l < r && nums[r] >= pivot)
                    r--;
                nums[l] = nums[r];
                while (l < r && nums[l] <= pivot)
                    l++;
                nums[r] = nums[l];
            }
            nums[l] = pivot;
            quick_sort(nums, left, l - 1);
            quick_sort(nums, l + 1, right);
        }
    }
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        quick_sort(nums, 0, nums.size() - 1);
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
        vector<int> res;
        for (auto &q : queries)
        {
            int l = 0, r = nums.size();
            while (l < r)
            {
                int m = (r - l) / 2 + l;
                if (nums[m] > q)
                    r = m;
                else
                    l = m + 1;
            }
            res.push_back(l);
            // res.push_back(upper_bound(nums.begin(), nums.end(), q) - nums.begin());
        }
        return res;
    }
};
// @lc code=end
