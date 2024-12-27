/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.82%)
 * Likes:    7848
 * Dislikes: 0
 * Total Accepted:    899.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */
#include "leetcode.h"
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++)
        {
            if (indices.count(target - nums[i]))
            {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;
        }
        return {};

        /* unordered_map<int, int> map;
        vector<int> ans;
        //可以先建立全部映射，再查找，这样不用下标+1
        for (int i = 0; i < nums.size(); i++)
        {
            if (map[target - nums[i]] && map[target - nums[i]] != i + 1)
            {
                ans.push_back(i);
                ans.push_back(map[target - nums[i]] - 1);
                return ans;
            }
            map[nums[i]] = i + 1; //将hash表对应下标＋1，防止处理下标为0的情况
        }
        return ans; */
    }
};
// @lc code=end
