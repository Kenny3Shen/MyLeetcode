/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (76.70%)
 * Likes:    878
 * Dislikes: 0
 * Total Accepted:    187.8K
 * Total Submissions: 244.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
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

public:
    void backtracking(vector<int> &nums, int begin)
    {
        if (begin == nums.size())
            res.push_back(nums);
        else
        {
            for (int i = begin; i < nums.size(); i++)
            {
                swap(nums[begin], nums[i]); //交换法
                backtracking(nums, begin + 1);
                swap(nums[begin], nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end
