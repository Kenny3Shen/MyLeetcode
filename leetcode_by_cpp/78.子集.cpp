/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.98%)
 * Likes:    749
 * Dislikes: 0
 * Total Accepted:    133K
 * Total Submissions: 170.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> subSet;

public:
    void backtrack(vector<int> &nums, int begin)
    {
        res.push_back(subSet);
        for (int i = begin; i < nums.size(); i++)
        {
            subSet.push_back(nums[i]);
            backtrack(nums, i + 1);
            subSet.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.empty())
            return res;
        backtrack(nums, 0);
        return res;
    }
};
// @lc code=end
