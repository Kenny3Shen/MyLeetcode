/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (69.58%)
 * Likes:    895
 * Dislikes: 0
 * Total Accepted:    149.3K
 * Total Submissions: 210.6K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1：
 * 
 * 输入：candidates = [2,3,6,7], target = 7,
 * 所求解集为：
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入：candidates = [2,3,5], target = 8,
 * 所求解集为：
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * candidate 中的每个元素都是独一无二的。
 * 1 <= target <= 500
 * 
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> combination;

public:
    void backtrack(vector<int> &candidates, int target, int begin)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i < candidates.size(); i++)
        {
            if (target - candidates[i] < 0) //必须为有序数组才可提前剪枝
                return;
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i);//i 是可以重复取的
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }
};
// @lc code=end
