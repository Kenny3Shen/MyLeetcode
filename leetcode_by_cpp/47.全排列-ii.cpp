/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (59.90%)
 * Likes:    420
 * Dislikes: 0
 * Total Accepted:    98.3K
 * Total Submissions: 161.3K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    void backtracking(vector<int> &nums, vector<int> &vec, vector<bool> &used)
    {
        // 此时说明找到了一组
        if (vec.size() == nums.size())
        {
            result.push_back(vec);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 这里理解used[i - 1]非常重要
            // used[i - 1] == true，说明同一树支nums[i - 1]使用过
            // used[i - 1] == false，说明同一树层nums[i - 1]使用过
            // 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            if (used[i] == false)
            {
                used[i] = true;
                vec.push_back(nums[i]);
                backtracking(nums, vec, used);
                vec.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> vec;
        backtracking(nums, vec, used);
        return result;
    }
};
// @lc code=end
